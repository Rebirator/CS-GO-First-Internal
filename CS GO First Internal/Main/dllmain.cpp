#include <Windows.h>
#include <iostream>
#include <thread>
#include "..\Main\Hack.hpp"
#include "..\Utils\Defines.hpp"
#include "..\SDK\Offsets.hpp"
#include "..\Utils\Module.hpp"
    
DWORD WINAPI HackThread( void* h_module ) {
    // Console
    AllocConsole( );
    freopen_s( ( FILE** )stdin, "CONIN$", "r", stdout );
    freopen_s( ( FILE** )stdout, "CONOUT$", "w", stdout );

    auto start_time = std::chrono::system_clock::now( );

    uintptr_t sig_test = g_module.Scan( "client.dll", "89 0D ? ? ? ? 8B 0D ? ? ? ? 8B F2 8B C1 83 CE 04", 2 );
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
    FreeLibraryAndExitThread( static_cast< HMODULE >( h_module ), EXIT_SUCCESS );
}

BOOL APIENTRY DllMain( HMODULE self, DWORD ul_reason_for_call, LPVOID lp_reserved ) {
    if ( ul_reason_for_call == DLL_PROCESS_ATTACH ) {
        HANDLE h_thread = CreateThread( nullptr, 0, &HackThread, self, 0, nullptr );
        if ( h_thread )
            CloseHandle( h_thread );
    }

    return TRUE;
}
