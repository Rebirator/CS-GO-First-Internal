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
    #ifdef __DEBUG__
        g_console.Attach( ); 
    #endif __DEBUG__
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
    #ifdef __DEBUG__
        g_console.Dettach( );
    #endif __DEBUG__

        Beep( 1100, 200 );
        fclose( stdin );
        fclose( stdout );
        FreeConsole( );
        FreeLibraryAndExitThread( static_cast< HMODULE >( h_module ), EXIT_SUCCESS );
    }
    catch ( const std::runtime_error &error ) {
        UNREFERENCED_PARAMETER( error );

    #ifdef __DEBUG__
        _RPT0( _CRT_ERROR, error.what( ) );
    #endif __DEBUG__

        Beep( 1500, 700 );
        fclose( stdin );
        fclose( stdout );
        FreeConsole( );
        FreeLibraryAndExitThread( static_cast< HMODULE >( h_module ), EXIT_SUCCESS );
    }
}

BOOL APIENTRY DllMain( HMODULE self, DWORD reason_for_call, LPVOID reserved ) {
    if ( reason_for_call == DLL_PROCESS_ATTACH ) {
    #ifndef __DEBUG__ // If release build
        DisableThreadLibraryCalls( self );
    #endif  __DEBUG__

        HANDLE entry_thread = CreateThread( nullptr, 0, &Entry, nullptr, 0, nullptr );
        if ( entry_thread != nullptr ) CloseHandle( entry_thread );

        HANDLE exit_thread  = CreateThread( nullptr, 0, &Exit, self, 0, nullptr );
        if ( exit_thread != nullptr ) CloseHandle( exit_thread );

        return TRUE;
    }

    delete reserved;
    return EXIT_SUCCESS;
}

#endif//__DLLMAIN__
