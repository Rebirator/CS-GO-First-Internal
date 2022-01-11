#pragma once

#include <Windows.h>

#include "Game/DTRecv.hpp"

class CNetVar {   
private:
    RecvProp GetPropPtrFromTable( const char* prop, RecvTable* recv_table );
    intptr_t GetPropOffsetFromTable( const char* prop, RecvTable* recv_table );

public:
    RecvProp GetPropPtr( const char* table, const char* prop );
    intptr_t GetPropOffset( const char* table, const char* prop );
}; extern CNetVar g_NetVar;

#define NETVAR( return_type, name, table, prop, object ) return_type name( ) { \
    return *reinterpret_cast< return_type* >( object + g_NetVar.GetPropOffset( table, prop ) ); \
}

#define NETVARA( return_type, name, table, prop, extra, object ) return_type name( ) { \
    return *reinterpret_cast< return_type* >( object + ( g_NetVar.GetPropOffset( table, prop ) + extra ) ); \
}
