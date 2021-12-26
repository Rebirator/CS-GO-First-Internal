#ifndef __CORE_CONSOLE_CONSOLE_HPP__
#define __CORE_CONSOLE_CONSOLE_HPP__

#include <iostream>

class C_Console {
private:
    FILE* f_stream_out;
    FILE* f_stream_in;

public:
    void Attach( const char* title = "Debug" );
    void Dettach( );
    void Print( const char* text );

    template< typename T, typename... Targs > void Print( const char* format, T value, Targs... f_args ) {
    #ifdef _DEBUG
        for ( ; *format != '\0'; format++ ) {
            if ( *format == '%' && *( format + 1 ) == 'x' ) {
                std::cout << std::hex << value;
                std::cout << std::dec;
                Print( format + 2, f_args... ); // recursive call
                return;
            }
            else if ( *format == '%' ) {
                std::cout << value;
                Print( format + 1, f_args... ); // recursive call
                return;
            }

            std::cout << *format;
        }
    #endif
    }
}; extern C_Console g_console;

#endif __CORE_CONSOLE_CONSOLE_HPP__
