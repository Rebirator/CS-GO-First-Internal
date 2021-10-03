#include "Module.hpp"
#include <iostream>
#include <sstream>

// Method BruteForce | Finds all signatures
uintptr Module::Scan( const wchar_t* module_t, const std::string signature, int offset, int extra, bool relative ) {
    auto [ begin, size ] = GetInfo( module_t );

    std::vector< BYTE > sig = Convert( signature );

    for ( uintptr cur_addr = begin; cur_addr < begin + size - sig.size( ); cur_addr++ )
    {
        for ( size_t sig_id = 0; sig_id < sig.size( ); sig_id++ )
        {
            if ( *reinterpret_cast< BYTE* >( cur_addr + sig_id ) != sig.at( sig_id ) && sig.at( sig_id ) != 0 )
                break;
            else if ( sig_id == sig.size( ) - 1 )
            {
                return relative ?
                    *reinterpret_cast< uintptr* >( cur_addr + offset ) + extra - begin :
                    *reinterpret_cast< uintptr* >( cur_addr + offset ) + extra;
            }
        }
    }

    return NULL;
}

// Method Boyer-Moore-Horspool | Does not always find signatures
uintptr Module::ScanFast( const wchar_t* module_t, const std::string signature, int offset, int extra, bool relative ) {
    auto [begin, size] = GetInfo( module_t );

    std::vector< BYTE > sig = Convert( signature );

    size_t max_shift = sig.size( );
    size_t max_id = sig.size( ) - 1;
    size_t wild_card_id = 0;
    for (size_t i = 0; i < max_id; i++) {
        if ( sig.at( i ) == -1 ) {
            max_shift = max_id - i;
            wild_card_id = i;
        }
    }

    size_t shift_table[ 256 ];
    for ( size_t i = 0; i <= 255; i++ ) {
        shift_table[ i ] = max_shift;
    }

    for ( size_t i = wild_card_id + 1; i < max_id - 1; i++ ) {
        shift_table[ sig.at( i ) ] = max_id - i;
    }

    for ( size_t cur_addr = begin; cur_addr < begin + size - sig.size( ); ) {
        for ( size_t sig_id = max_id; sig_id >= 0 && sig_id < sig.size( ) + 1; sig_id-- ) {
            if ( *reinterpret_cast< BYTE* >( cur_addr + sig_id ) != sig.at( sig_id ) && sig.at( sig_id ) != 0 ) {
                cur_addr += shift_table[ *reinterpret_cast< BYTE* >( cur_addr + max_id ) ];
                break;
            }
            else if ( sig_id == 0 ) {
                return relative ?
                    *reinterpret_cast< uintptr* >( cur_addr + offset ) + extra - begin :
                    *reinterpret_cast< uintptr* >( cur_addr + offset ) + extra;
            }
        }
    }

    return NULL;
}

std::vector< BYTE > Module::Convert( const std::string &signature ) {
    std::vector< BYTE > converted_sig { };
    std::stringstream	stream_sig { signature };
    std::string		    w;

	while( stream_sig >> w ) {
        // if wild card then replace to -1
        if ( w[ 0 ] == '?' )
            converted_sig.push_back( 0 );
		// if valid hex digits
		if( std::isxdigit( w[0] ) && std::isxdigit( w[1] ) )
			converted_sig.push_back( ( BYTE )std::strtoul( w.data( ), 0, 16 ) );
	}

    return converted_sig;
}

std::tuple< uintptr, size_t > Module::GetInfo( const wchar_t* module_t ) {
    HMODULE h_module = GetModuleHandle( module_t );

    if ( !h_module )
        return { NULL, NULL };

    MODULEINFO module_info = ( MODULEINFO )NULL;
    GetModuleInformation( GetCurrentProcess( ), h_module, &module_info, sizeof( MODULEINFO ) );

    return { 
        ( uintptr )module_info.lpBaseOfDll, 
        module_info.SizeOfImage 
    };
}
