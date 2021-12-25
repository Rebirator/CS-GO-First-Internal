#ifndef __UTILS_STRINGS_HPP__
#define __UTILS_STRINGS_HPP__

#include <string>

namespace g_utils::string {
    inline std::string ToString( const char* string ) {
        std::string buffer( string );
        return buffer;
    }
}

#endif//__UTILS_STRINGS_HPP__
