#pragma once

#include <d3d11.h>
#include <dxgi.h>

class Renderer {
public:
    bool initDevice(HWND hWnd);
    bool render();
    bool resize(UINT width, UINT height);
    void releaseMemory();

private:
    HRESULT setupBackBuffer();

    ID3D11Device* m_pDevice = nullptr;
    ID3D11DeviceContext* m_pDeviceContext = nullptr;
    IDXGISwapChain* m_pSwapChain = nullptr;
    ID3D11RenderTargetView* m_pBackBufferRTV = nullptr;
    UINT m_width = 0;
    UINT m_height = 0;
};