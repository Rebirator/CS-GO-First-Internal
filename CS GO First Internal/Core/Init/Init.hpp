#ifndef __CORE_INIT_INIT_HPP__
#define __CORE_INIT_INIT_HPP__

class Init {
public:
    void InterfacesInit( );
    void HooksInit( );
    void HooksRelease( );

public:
    void InitAll( );
    void ReleaseAll( );
}; extern Init g_Init;

#endif __CORE_INIT_INIT_HPP__
