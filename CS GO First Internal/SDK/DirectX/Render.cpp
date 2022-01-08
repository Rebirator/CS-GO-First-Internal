#include "Render.hpp"
#include "D3DX9.hpp"

void g_Render::FilledRect( int x1, int y1, int x2, int y2, Color color ) {
    D3DRECT rect = { x1, y1, x2, y2 };
    g_DirectDevice->Clear( 1, &rect, D3DCLEAR_TARGET, D3DCOLOR_RGBA( color.a, color.g, color.b, color.a ), 0, 0 );
}
