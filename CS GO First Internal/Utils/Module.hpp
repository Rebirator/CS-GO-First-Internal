#ifndef __UTIL_MODULE__
#define __UTIL_MODULE__

#include <Windows.h>
#include <Psapi.h>
#include <vector>
#include <string>
#include "Singleton.hpp"
#include "Defines.hpp"

class Module : public Singleton< Module > {
public:
	uintptr Scan( const wchar_t* module_t, const std::string signature, int offset = 0, int extra = 0, bool relative = true );
	uintptr ScanFast( const wchar_t* module_t, const std::string signature, int offset = 0, int extra = 0, bool relative = true );

	std::tuple< uintptr, size_t > GetInfo( const wchar_t* module_t );
	std::vector< BYTE > Convert( const std::string &signature );
};

#endif//__UTIL_MODULE__
