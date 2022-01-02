#ifndef __UTILS_MISC_HPP__
#define __UTILS_MISC_HPP__

#include <Windows.h>

namespace g_utils::misc {
    template< class T > T VFunction( void* this_ptr, uintptr_t index ) {
        return *static_cast< T** >( this_ptr )[ index ];
    }
}

#endif  __UTILS_MISC_HPP__