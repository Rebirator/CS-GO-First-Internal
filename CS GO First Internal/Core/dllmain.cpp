#ifndef __DLLMAIN__
#define __DLLMAIN__

#include <Windows.h>
#include <iostream>
#include <thread>

#include "Console/Console.hpp"
#include "Init/Init.hpp"
#include "Hack/Hack.hpp"
    
DWORD WINAPI Entry( void* h_module ) {
    try {
        g_console.Attach( );

        g_init.InitAll( );

        while ( !GetAsyncKeyState( VK_END ) ) {
            Hack( );

            std::this_thread::sleep_for( std::chrono::milliseconds( 1 ) );
        }
    }
    catch ( const std::runtime_error &error ) {
        UNREFERENCED_PARAMETER( error );

    #ifdef _DEBUG
        _RPT0( _CRT_ERROR, error.what( ) );
    #endif _DEBUG

        Beep( 1500, 700 );
        fclose( stdin );
        fclose( stdout );
        FreeConsole( );
        FreeLibraryAndExitThread( static_cast< HMODULE >( h_module ), EXIT_SUCCESS );
    }

    return EXIT_SUCCESS;
}

DWORD WINAPI Exit( void* h_module ) {
    while ( !GetAsyncKeyState( VK_END ) )
        std::this_thread::sleep_for( std::chrono::milliseconds( 100 ) );

    try {
        g_console.Dettach( );

        Beep( 1100, 200 );
        fclose( stdin );
        fclose( stdout );
        FreeConsole( );
        FreeLibraryAndExitThread( static_cast< HMODULE >( h_module ), EXIT_SUCCESS );
    }
    catch ( const std::runtime_error &error ) {
        UNREFERENCED_PARAMETER( error );

    #ifdef _DEBUG
        _RPT0( _CRT_ERROR, error.what( ) );
    #endif _DEBUG

        Beep( 1500, 700 );
        fclose( stdin );
        fclose( stdout );
        FreeConsole( );
        FreeLibraryAndExitThread( static_cast< HMODULE >( h_module ), EXIT_SUCCESS );
    }

    return EXIT_SUCCESS;
}

BOOL APIENTRY DllMain( HMODULE self, DWORD ul_reason_for_call, LPVOID lp_reserved ) {
    if ( ul_reason_for_call == DLL_PROCESS_ATTACH ) {
    #ifndef _DEBUG // If release build
        DisableThreadLibraryCalls( self );
    #endif  _DEBUG

        HANDLE entry_thread = CreateThread( nullptr, 0, &Entry, nullptr, 0, nullptr );
        if ( entry_thread != nullptr ) CloseHandle( entry_thread );

        HANDLE exit_thread  = CreateThread( nullptr, 0, &Exit, self, 0, nullptr );
        if ( exit_thread != nullptr ) CloseHandle( exit_thread );

        return TRUE;
    }

    return EXIT_SUCCESS;
}

#endif//__DLLMAIN__
