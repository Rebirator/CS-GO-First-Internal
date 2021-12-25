#ifndef __SDK_INTERFACES_HPP__
#define __SDK_INTERFACES_HPP__

#include <Windows.h>
#include <iostream>
#include "../Utils/Strings.hpp"
#include "Interfaces/IClientUnknown.hpp"
#include "Interfaces/IClientNetworkable.hpp"
#include "Interfaces/IClientEntityList.hpp"

typedef void* ( _cdecl* Type_CreateInterface )( const char* name, int* return_code );

class Interfaces {
public:
    IClientUnknown*     p_client_unknown        = nullptr;
    IClientNetworkable* p_client_networkable    = nullptr;
    IClientEntityList*  p_client_entitylist     = nullptr;
}; extern Interfaces g_interfaces;

class Interface {
private:
    template< class Interface_ > Interface_* CreateInterface( const char* dllmodule, const char* interface_name ) {
        Type_CreateInterface create_interface = reinterpret_cast< Type_CreateInterface >( GetProcAddress( GetModuleHandleA( dllmodule ), "CreateInterface" ) );
        if ( create_interface == nullptr )
            return nullptr;

        int return_code = 0;
        Interface_* interface_ = reinterpret_cast< Interface_* >( create_interface( interface_name, &return_code ) );

        return interface_;
    }

public:
    template< class Interface_ > void GetInterface( Interface_* &interface_, const char* dllmodule, const char* interface_name ) {
        interface_ = CreateInterface< Interface_ >( dllmodule, interface_name );

        if ( interface_ == nullptr )
            throw std::runtime_error( g_utils::string::ToString( interface_name ) + " is nullptr" );
        else if ( IsBadReadPtr( interface_, sizeof( void* ) ) )
            throw std::runtime_error( g_utils::string::ToString( interface_name ) + " is invalid ptr" );
    }
}; extern Interface g_interface;

#endif//__SDK_INTERFACES_HPP__
