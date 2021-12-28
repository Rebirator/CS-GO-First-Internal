#ifndef __CORE_HOOKS_HOOK_MANAGER_HPP__
#define __CORE_HOOKS_HOOK_MANAGER_HPP__

#include <Windows.h>

class Hook {
private:
    BYTE* x_target;
    BYTE  x_original_bytes[ 10 ];
    BYTE* x_source;
    BYTE* p_gateway_fn;
    short i_length;

    bool  Detour_x86( BYTE* target, BYTE* source, short length );
    BYTE* Trampoline_x86( BYTE* target, BYTE* source, short length );

public:
    template< class Type_Function > void Create( BYTE* target, BYTE* source, short length );
    template< class Type_Function > void Create( const char* dllmodule, const char* function_name, BYTE* source, short length );

    void Enable( );
    void Disable( );
}; extern Hook g_hook;

#endif  __CORE_HOOKS_HOOK_MANAGER_HPP__
