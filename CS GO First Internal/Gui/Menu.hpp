#ifndef __GUI_MENU_HPP__
#define __GUI_MENU_HPP__

class CMenu {
private:
    void Top( );
    void TabLegit( );
    void TabESP( );
    void TabSettings( );

public:
    void Render( );
}; extern CMenu g_Menu;

#endif  __GUI_MENU_HPP__
