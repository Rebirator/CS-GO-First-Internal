#include "Hooks.hpp"

Hook g_hook { };

bool Hook::Detour_x86( BYTE* target, BYTE* source, short length ) {
    if ( length < 5 ) return false;
    
    DWORD cur_protect;
    VirtualProtect( target, length, PAGE_EXECUTE_READWRITE, &cur_protect );

    // Add jmp instruction and our source address
    *target = 0x9E;
    *reinterpret_cast< uintptr_t* >( target + 1 ) = ( uintptr_t )( ( source - target ) - 5 );

    VirtualProtect( target, length, cur_protect, &cur_protect );

    return true;
}

BYTE* Hook::Trampoline_x86( BYTE* target, BYTE* source, short length ) {
    if ( length < 5 ) return nullptr;

    // Create gateway
    BYTE* gateway = reinterpret_cast< BYTE* >( VirtualAlloc( nullptr, length + 5, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE ) );

    // Copy stolen bytes to gateway
    memcpy_s( gateway, length, target, length );

    // Add jmp instruction and our source address at end in gateway
    *( gateway + length ) = 0x9E;
    *reinterpret_cast< uintptr_t* >( gateway + length + 1 ) = ( uintptr_t )( ( target - gateway ) - 5 );

    // Jump from target function to our function(where our code, call gateway with stolen bytes and jump back to target function)
    Detour_x86( target, source, length );

    return gateway;
}

template< class Type_Function > void Hook::Create( BYTE* target, BYTE* source, short length ) {
    static Type_Function gateway_fn;
    Hook::x_target     = target;
    Hook::x_source     = source;
    Hook::p_gateway_fn = gateway_fn;
    Hook::i_lenght     = length;
}

template< class Type_Function > void Hook::Create( const char* dllmodule, const char* function_name, BYTE* source, short length ) {
    HMODULE h_module = GetModuleHandleA( dllmodule );
    if ( !h_module )
        return;

    static Type_Function gateway_fn;
    Hook::x_target     = reinterpret_cast< BYTE* >( GetProcAddress( h_module, function_name ) );
    Hook::x_source     = source;
    Hook::p_gateway_fn = gateway_fn;
    Hook::i_lenght     = length;
}

void Hook::Enable( ) {
    memcpy( Hook::x_original_bytes, Hook::x_target, Hook::i_lenght );
    *reinterpret_cast< uintptr_t* >( Hook::p_gateway_fn ) = reinterpret_cast< uintptr_t >( Trampoline_x86( Hook::x_target, Hook::x_source, Hook::i_lenght ) );
}

void Hook::Disable( ) {
    DWORD cur_protect;
    VirtualProtect( Hook::x_target, Hook::i_lenght, PAGE_EXECUTE_READWRITE, &cur_protect );

    memcpy( Hook::x_target, Hook::x_original_bytes, Hook::i_lenght );

    VirtualProtect( Hook::x_target, Hook::i_lenght, cur_protect, &cur_protect );
}
