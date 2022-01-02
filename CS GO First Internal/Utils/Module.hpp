#ifndef __UTILS_MODULE_HPP__
#define __UTILS_MODULE_HPP__

#include <Windows.h>
#include <Psapi.h>
#include <vector>
#include <string>
#include "Defines.hpp"

class Module {
public:
	std::vector< BYTE > Convert( const std::string &signature );
	uintptr_t Scan( const char* module_t, const std::string signature, int extra = 0, bool relative = true );

	struct PE_Info {
		uintptr_t m_base;
		uintptr_t m_size;

		PE_Info( const char* module_t );
	};
}; extern Module g_module;

#endif __UTILS_MODULE_HPP__
