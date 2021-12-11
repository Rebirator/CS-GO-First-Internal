#include "Module.hpp"
#include <iostream>
#include <sstream>

Module g_module { };

std::vector< BYTE > Module::Convert( const std::string &signature ) {
    std::vector< BYTE > converted_sig { };
    std::stringstream	stream_sig { signature };
    std::string		    w;

    while ( stream_sig >> w ) {
        // If wild card then replace to 0
        if ( w[ 0 ] == '?' )
            converted_sig.push_back( 0 );
        // If valid hex digits
        if ( std::isxdigit( w[ 0 ] ) && std::isxdigit( w[ 1 ] ) )
            converted_sig.push_back( ( BYTE )std::strtoul( w.data( ), 0, 16 ) );
    }

    return converted_sig;
}

uintptr_t Module::Scan( const char* module_t, const std::string signature, int extra, bool relative ) {
    PE_Info mod_info( module_t );

    std::vector< BYTE > sig = Convert( signature );

    for ( uintptr_t cur_addr = mod_info.m_base; cur_addr < mod_info.m_base + mod_info.m_size - sig.size( ); cur_addr++ )
    {
        for ( size_t sig_id = 0; sig_id < sig.size( ); sig_id++ )
        {
            if ( *reinterpret_cast< BYTE* >( cur_addr + sig_id ) != sig.at( sig_id ) && sig.at( sig_id ) != 0 )
                break;
            else if ( sig_id == sig.size( ) - 1 )
            {
                return relative ?
                    *reinterpret_cast< uintptr_t* >( cur_addr ) + extra - mod_info.m_base :
                    *reinterpret_cast< uintptr_t* >( cur_addr ) + extra;
            }
        }
    }

    return NULL;
}

Module::PE_Info::PE_Info( const char* module_t ) {
    HMODULE h_module = GetModuleHandleA( module_t );
    if ( !h_module )
        return;

    MODULEINFO module_info;
    GetModuleInformation( GetCurrentProcess( ), h_module, &module_info, sizeof( MODULEINFO ) );

    this->m_base = ( uintptr_t )module_info.lpBaseOfDll;
    this->m_size = module_info.SizeOfImage;
}
