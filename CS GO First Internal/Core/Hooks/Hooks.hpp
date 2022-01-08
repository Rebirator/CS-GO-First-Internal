#ifndef __CORE_HOOKS_HOOK_MANAGER_HPP__
#define __CORE_HOOKS_HOOK_MANAGER_HPP__

#include <Windows.h>

class Hook {
public:
    BYTE* m_xTarget;
    BYTE  m_xOriginalBytes[ 10 ] { 0 };
    BYTE* m_xSource;
    BYTE* m_pGatewayFn;
    short m_iLength;

    void  Detour_x86( BYTE* target, BYTE* source, short length );
    BYTE* Trampoline_x86( BYTE* target, BYTE* source, short length );

public:
    Hook( ) { };
    Hook( BYTE* target, BYTE* source, BYTE* original, short length );
    Hook( const char* dllmodule, const char* function_name, BYTE* source, BYTE* original, short length );

    void Enable( );
    void Disable( );
}; extern Hook g_Hook;

#endif  __CORE_HOOKS_HOOK_MANAGER_HPP__
