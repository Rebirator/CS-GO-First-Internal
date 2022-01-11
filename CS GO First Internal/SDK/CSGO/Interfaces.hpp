#ifndef __SDK_INTERFACES_HPP__
#define __SDK_INTERFACES_HPP__

#pragma warning( disable: 6387 )

#include <Windows.h>
#include <iostream>

#include "Interfaces/IClientUnknown.hpp"
#include "Interfaces/IClientNetworkable.hpp"
#include "Interfaces/IClientEntityList.hpp"
#include "Interfaces/ICHLClient .hpp"

class CInterfaces {
public:
    IClientUnknown*     m_pClientUnknown        = nullptr;
    IClientNetworkable* p_mClientNetworkable    = nullptr;
    IClientEntityList*  m_pClientEntityList     = nullptr;
    ICHLClient*         m_pClient               = nullptr;
}; extern CInterfaces g_Interfaces;

class CInterface {
private:
    template< class Interface > Interface* CreateInterface( const char* dllmodule, const char* interface_name ) {
        using CreateInterfaceFn = void* ( _cdecl* )( const char* name, int* return_code );
        CreateInterfaceFn create_interface_fn = reinterpret_cast< CreateInterfaceFn >( GetProcAddress( GetModuleHandleA( dllmodule ), "CreateInterface" ) );

        int return_code = 0;
        return reinterpret_cast< Interface* >( create_interface_fn( interface_name, &return_code ) );
    }

public:
    template< class Interface > void GetInterface( Interface* &interface_, const char* dllmodule, const char* interface_name ) {
        interface_ = CreateInterface< Interface >( dllmodule, interface_name );

        if ( interface_ == nullptr )
            throw std::runtime_error( std::string( interface_name ) + " is nullptr" );
        else if ( IsBadReadPtr( interface_, sizeof( void* ) ) )
            throw std::runtime_error( std::string( interface_name ) + " is invalid ptr" );
    }
}; extern CInterface g_Interface;

#endif//__SDK_INTERFACES_HPP__
