#include "Hooks.hpp"

Hook g_Hook { 0, 0, 0, 0 };

void Hook::Detour_x86( BYTE* target, BYTE* source, short length ) {
	if ( length < 5 ) return;

	DWORD cur_protect;
	VirtualProtect( target, length, PAGE_EXECUTE_READWRITE, &cur_protect );

	// Clear target memory
	memset( target, 0x90, length );

	// Add jmp instruction and our source address
	*target = 0xE9;
	*reinterpret_cast< uintptr_t* >( target + 1 ) = source - target - 5;

	VirtualProtect( target, length, cur_protect, &cur_protect );
}

BYTE* Hook::Trampoline_x86( BYTE* target, BYTE* source, short length ) {
	if ( length < 5 ) return 0;

	// Create gateway
	BYTE* gateway = reinterpret_cast< BYTE* >( VirtualAlloc( 0, length + 5, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE ) );

	// Copy stolen bytes to gateway
	memcpy( gateway, target, length );

	// Add jmp instruction and our source address at end in gateway
	*( gateway + length ) = 0xE9;
	*reinterpret_cast< uintptr_t* >( gateway + length + 1 ) = target - gateway - 5;

	// Jump from target function to our function(where our code, call gateway with stolen bytes and jump back to target function)
	Detour_x86( target, source, length );

	return gateway;
}

Hook::Hook( BYTE* target, BYTE* source, BYTE* original, short length ) {
    this->m_xTarget    = target;
    this->m_xSource    = source;
    this->m_pGatewayFn = original;
    this->m_iLength    = length;
}

Hook::Hook( const char* dllmodule, const char* function_name, BYTE* source, BYTE* original, short length ) {
    if ( HMODULE h_module = GetModuleHandleA( dllmodule ); h_module ) {
        this->m_xTarget    = reinterpret_cast< BYTE* >( GetProcAddress( h_module, function_name ) );
        this->m_xSource    = source;
        this->m_pGatewayFn = original;
        this->m_iLength    = length;
    }
}

void Hook::Enable( ) {
    memcpy( this->m_xOriginalBytes, this->m_xTarget, this->m_iLength );
    *reinterpret_cast< uintptr_t* >( this->m_pGatewayFn ) = reinterpret_cast< uintptr_t >( Trampoline_x86( Hook::m_xTarget, Hook::m_xSource, Hook::m_iLength ) );
}
    
void Hook::Disable( ) {
    DWORD cur_protect;
    VirtualProtect( this->m_xTarget, this->m_iLength, PAGE_EXECUTE_READWRITE, &cur_protect );

    memcpy( this->m_xTarget, this->m_xOriginalBytes, this->m_iLength );

    VirtualProtect( this->m_xTarget, this->m_iLength, cur_protect, &cur_protect );
}
