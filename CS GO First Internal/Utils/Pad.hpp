#ifndef __UTILS_PAD_HPP__
#define __UTILS_PAD_HPP__

#define CONCAT( a, b ) a##b
#define PAD_NAME( n ) CONCAT( pad, n )

#define PAD(size) \
private: \
    std::byte PAD_NAME( __LINE__ ) [ size ]; \
public:

#endif//__UTILS_PAD_HPP__
