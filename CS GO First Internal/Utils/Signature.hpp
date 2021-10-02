#ifndef __SIGNATURE__
#define __SIGNATURE__

#include <Windows.h>
#include <Psapi.h>
#include <vector>
#include "Singleton.hpp"
#include "Defines.hpp"

class Signature : public Singleton< Signature > {
public:
	uintptr Scan( const wchar_t* module_t, std::vector< int > signature, int offset = 0, int extra = 0, bool relative = true );

private:
	std::tuple< uintptr, size_t > GetModuleInfo( const wchar_t* module_t );
	BYTE* GetData( uintptr begin, size_t size );
};

#endif//__SIGNATURE__
