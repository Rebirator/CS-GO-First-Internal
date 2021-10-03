#include <Windows.h>
#include <iostream>
#include <thread>
#include "..\Main\Hack.hpp"
#include "..\Utils\Defines.hpp"
#include "..\SDK\Offsets.hpp"
#include "..\Utils\Module.hpp"

DWORD WINAPI HackThread( HMODULE hModule )
{
    // Console
    AllocConsole( );
    freopen_s( ( FILE** )stdin, "CONIN$", "r", stdout );
    freopen_s( ( FILE** )stdin, "CONOUT$", "w", stdout );

    auto start_time = std::chrono::system_clock::now( );

    uintptr sig_test = g_Module->Scan( L"client.dll", "89 0D ? ? ? ? 8B 0D ? ? ? ? 8B F2 8B C1 83 CE 04", 2 );
    std::cout << std::hex << std::uppercase << "dwForceAttack offset: 0x" << sig_test << std::endl;

    auto end_time = std::chrono::system_clock::now( );
    std::cout << "Signature parsed in:   " << std::chrono::duration< double >( end_time - start_time ).count( ) << std::endl;

    // Main loop
    while ( !GetAsyncKeyState( VK_INSERT ) ) {
        // Cheat
        Hack( );

        std::this_thread::sleep_for( std::chrono::milliseconds( 1 ) );
    }

    // Exit
    fclose( stdin );
    fclose( stdout );
    FreeConsole( );
    FreeLibraryAndExitThread( hModule, 0 );
}

BOOL APIENTRY DllMain( HMODULE hModule,  DWORD  ul_reason_for_call, LPVOID lpReserved )
{
    switch ( ul_reason_for_call )
    {
    case DLL_PROCESS_ATTACH:
    {
        HANDLE h_thread = CreateThread( nullptr, 0, ( LPTHREAD_START_ROUTINE )HackThread, hModule, 0, nullptr );
        if ( h_thread )
            CloseHandle( h_thread );
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }

    // shutting up the compiler
    LPVOID lpReserv = lpReserved;
    delete lpReserv;

    // ret
    return TRUE;
}
