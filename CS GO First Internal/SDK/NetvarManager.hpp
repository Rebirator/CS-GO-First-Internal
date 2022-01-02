#ifndef __SDK_NETVARMANAGER_HPP__
#define __SDK_NETVARMANAGER_HPP__

#include <Windows.h>

#include "Game/ClientClass.hpp"
#include "Game/DTRecv.hpp"
#include "Interfaces.hpp"

class CNetvar {
private:
    RecvProp GetPropPtrFromTable( const char* prop, RecvTable* recv_table );
    intptr_t GetPropOffsetFromTable( const char* prop, RecvTable* recv_table );
    
public:
    RecvProp GetPropPtr( const char* table, const char* prop );
    intptr_t GetPropOffset( const char* table, const char* prop );
}; extern CNetvar g_netvar;

#endif  __SDK_NETVARMANAGER_HPP__
