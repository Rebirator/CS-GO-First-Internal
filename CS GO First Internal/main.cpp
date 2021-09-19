#include <Windows.h>
#include <iostream>
#include <bitset>
#include <TlHelp32.h>
#include "func_offsets.h"
#include <cmath>

struct Vector3 {
    float x, y, z;
};

using namespace hazedumper;

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
    FILE* f;
    freopen_s( &f, "CONOUT$", "w", stdout );

    while ( true )
    {
        if ( !GetLocalPlayer( ) ) {
            do {
                GetLocalPlayer( );
                return EXIT_FAILURE;
            } while ( !GetLocalPlayer( ) );
        }

        uintptr_t LocalPlayer = GetLocalPlayer( );

        FuncsController( );

        if ( bunnyhop ) {
            while ( GetAsyncKeyState( VK_SPACE ) ) {
                uintptr_t flags = Funcs.GetEntityFlags( LocalPlayer );

                if ( flags & ( 1 << 0 ) ) {
                    SetValue< BYTE >( g_Game::GameModule + signatures::dwForceJump, 6 );
                }
            }
        }

        if ( radarhack ) {
            for ( short int i = 0; i < 64; i++ ) {
                uintptr_t entity = Funcs.GetEntityByIndex( i );

                if ( entity ) {
                    int entity_team = Funcs.GetEntityTeam( entity );

                    if ( entity_team != Funcs.GetEntityTeam( LocalPlayer ) )
                        SetValue< bool >( entity + netvars::m_bSpotted, 1 );
                }
            }
        }

        if ( antiflash ) {
            SetValue< int >( LocalPlayer + netvars::m_flFlashDuration, 0 );
        }

        if ( triggerbot ) {
            int Crosshair = GetValue< int >( LocalPlayer + netvars::m_iCrosshairId );

            if ( Crosshair > 0 && Crosshair <= 64 ) {
                uintptr_t Entity = Funcs.GetEntityByIndex( Crosshair - 1 );

                if ( GetValue< int >( Entity + netvars::m_iHealth ) > 0 ) {
                    Vector3 LocalPos = GetValue< Vector3 >( LocalPlayer + netvars::m_vecOrigin );
                    Vector3 EntityPos = GetValue< Vector3 >( Entity + netvars::m_vecOrigin );
                    double Distance = abs( LocalPos.x - EntityPos.x + LocalPos.y - EntityPos.y + LocalPos.z - EntityPos.z ) * 0.0254;

                    Sleep( ( int )Distance * 5 );
                    SetValue< BYTE >( g_Game::GameModule + signatures::dwForceAttack, 6 );
                }
            }
        }

        if ( GetAsyncKeyState( VK_INSERT ) ) {
            fclose( f );
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