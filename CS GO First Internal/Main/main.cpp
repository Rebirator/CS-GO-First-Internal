#include <Windows.h>
#include <iostream>
#include <cmath>
#include "..\Main\Hack.hpp"
#include "..\Utils\Defines.hpp"

DWORD WINAPI HackThread( HMODULE hModule )
{
    // Console
    AllocConsole( );
    FILE* F_Console;
    freopen_s( &F_Console, "CONOUT$", "w", stdout );

    while ( true )
    {
        Hack( );

        if ( GetAsyncKeyState( VK_INSERT ) ) {
            if ( F_Console )
                fclose( F_Console );
            FreeConsole( );
            FreeLibraryAndExitThread( hModule, 0 );
            return EXIT_SUCCESS;
        }

        Sleep( 1 );
    }
}

BOOL APIENTRY DllMain( HMODULE hModule,  DWORD  ul_reason_for_call, LPVOID lpReserved )
{
    switch ( ul_reason_for_call )
    {
    case DLL_PROCESS_ATTACH:
    {
        CloseHandle( CreateThread( nullptr, 0, ( LPTHREAD_START_ROUTINE )HackThread, hModule, 0, nullptr ) );
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
