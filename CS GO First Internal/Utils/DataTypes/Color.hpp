#ifndef __UTILS_DATATYPES_COLOR_HPP__
#define __UTILS_DATATYPES_COLOR_HPP__

class Color {
public:
    int r, g, b, a;

    Color( ) { Color( 255, 255, 255, 255 ); }
    Color( int _r, int _g, int _b, int _a ) {
        this->r = _r;
        this->g = _g;
        this->b = _b;
        this->a = _a;
    }
};

#endif  __UTILS_DATATYPES_COLOR_HPP__
