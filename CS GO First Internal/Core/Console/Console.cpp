#include <Windows.h>

#include "Console.hpp"

C_Console g_console { };

void C_Console::Attach( const char* title ) {
    if ( !AllocConsole( ) )
        throw std::runtime_error( "Failed to allocate console!" );

    if ( AttachConsole( ATTACH_PARENT_PROCESS ) )                        // It get error code, if == 0, then OK, else error
        throw std::runtime_error( "Failed attach to console!" );

    if ( freopen_s( &f_stream_out, "CONOUT$", "w", stdout ) )            // It get error code, if == 0, then OK, else error
        throw std::runtime_error( "Failed to open stdout filestream!" );

    if ( freopen_s( &f_stream_in, "CONIN$", "r", stdin ) )               // It get error code, if == 0, then OK, else error
        throw std::runtime_error( "Failed to open stdin filestream!" );

    if ( !SetConsoleTitleA( title ) )
        throw std::runtime_error( "Failed to set title!" );
}

void C_Console::Dettach( ) {
    if ( fclose( f_stream_out ) )                                        // It get error code, if == 0, then OK, else error
        throw std::runtime_error( "Failed to close stdout filestream!" );

    if ( fclose( f_stream_in ) )                                         // It get error code, if == 0, then OK, else error
        throw std::runtime_error( "Failed to close stdin filestream!" );

    if ( !FreeConsole( ) )
        throw std::runtime_error( "Failed to close console!" );
}

void C_Console::Print( const char* text ) {
#ifdef _DEBUG
    std::cout << text;
#endif _DEBUG
}
