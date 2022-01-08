#include "D3DX9.hpp"

void* D3D9Device[ 119 ];
LPDIRECT3DDEVICE9 g_DirectDevice;

BOOL CALLBACK EnumWind( HWND handle, LPARAM lp ) {
    DWORD proc_id;

    GetWindowThreadProcessId( handle, &proc_id );
    if ( GetCurrentProcessId( ) != proc_id )
        return EXIT_FAILURE;

    g_hwndWindow = handle;
    return EXIT_SUCCESS;
}

HWND GetProcessWindow( ) {
    EnumWindows( EnumWind, 0 );
    return g_hwndWindow;
}

bool GetD3D9Device( void** table, size_t size ) {
    if ( table != nullptr ) {
        IDirect3D9* d3d = Direct3DCreate9( D3D_SDK_VERSION );

        if ( d3d != nullptr ) {
            IDirect3DDevice9* dummy_device = nullptr;

            D3DPRESENT_PARAMETERS d3dpp = { };
            d3dpp.Windowed = false;
            d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
            d3dpp.hDeviceWindow = GetProcessWindow( );

            HRESULT dummy_dev_created = d3d->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, d3dpp.hDeviceWindow, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &dummy_device );

            if ( dummy_dev_created != S_OK ) {
                d3dpp.Windowed = !d3dpp.Windowed;
                dummy_dev_created = d3d->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, d3dpp.hDeviceWindow, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &dummy_device );
                if ( dummy_dev_created != S_OK ) {
                    d3d->Release( );
                    return false;
                }
            }

            memcpy( table, *reinterpret_cast< void*** >( dummy_device ), size );
            dummy_device->Release( );
            d3d->Release( );
            return true;
        }
    }

    return false;
}
