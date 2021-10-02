#include "Signature.hpp"

uintptr Signature::Scan( const wchar_t* module_t, std::vector< int > signature, int offset, int extra, bool relative ) {
    auto [ begin, size ] = GetModuleInfo( module_t );
    BYTE* data = GetData( begin, size );

    for ( uintptr buf_addr = 0; buf_addr < size - signature.size( ); buf_addr++ ) {
        for ( size_t sig_id = 0; sig_id < signature.size( ); sig_id++ ) {
            if ( data[ buf_addr + sig_id ] != signature.at( sig_id ) && signature.at( sig_id ) != -1 )
                break;
            else if ( sig_id == signature.size( ) - 1 ) {
                return relative ? 
                    *reinterpret_cast< uintptr* >( begin + buf_addr + offset ) + extra - begin :
                    *reinterpret_cast< uintptr* >( begin + buf_addr + offset ) + extra;
            }
        }
    }

    return NULL;
}

std::tuple< uintptr, size_t > Signature::GetModuleInfo( const wchar_t* module_t ) {
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

BYTE* Signature::GetData( uintptr begin, size_t size ) {
    BYTE* buffer = new BYTE[ size ];

    memcpy( buffer, ( void* )begin, size );

    return buffer;
}
