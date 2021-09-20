#include <Windows.h>
#include <iostream>
#include <cmath>
#include "..\SDK\Entity.h"
#include "..\SDK\Offsets.h"

bool bunnyhop = false, radarhack = false, antiflash = false, triggerbot = false;

void FuncsController( )
{
    if ( GetAsyncKeyState( VK_F1 ) & 1 ) {
        bunnyhop = !bunnyhop;
        std::cout << "Bhop " << bunnyhop << std::endl;
    }

    if ( GetAsyncKeyState( VK_F2 ) & 1 ) {
        radarhack = !radarhack;
        std::cout << "RadarHack " << radarhack << std::endl;
    }

    if ( GetAsyncKeyState( VK_F3 ) & 1 ) {
        antiflash = !antiflash;
        std::cout << "AntiFlash " << antiflash << std::endl;
    }

    if ( GetAsyncKeyState( VK_F4 ) & 1 ) {
        triggerbot = !triggerbot;
        std::cout << "TriggerBot " << triggerbot << std::endl;
    }
}

DWORD WINAPI HackThread( HMODULE hModule )
{
    // Console
    AllocConsole( );
    FILE* F_Console;
    freopen_s( &F_Console, "CONOUT$", "w", stdout );

    while ( true )
    {
        Entity* LocalPlayer = *reinterpret_cast< Entity** >( g_Game::GameModule + g_Signatures::dwLocalPlayer );

        std::cout << LocalPlayer->GetTeam( ) << std::endl;

        if ( GetAsyncKeyState( VK_INSERT ) ) {
            if ( F_Console )
                fclose( F_Console );
            FreeConsole( );
            FreeLibraryAndExitThread( hModule, 0 );
            return EXIT_SUCCESS;
        }

        Sleep( 2 );
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