#pragma once

#include <d3d11.h>
#include <dxgi.h>
#include <d3dcompiler.h>
#include "camera.hpp"
#include "input.hpp"

struct Vertex
{
    float x, y, z;
    COLORREF color;
};

struct WorldMatrixBuffer {
    XMMATRIX mWorldMatrix;
};

struct SceneMatrixBuffer {
    XMMATRIX mViewProjectionMatrix;
};

class Renderer {
public:
    bool InitDevice(HINSTANCE hInstance, HWND hWnd);
    bool Render();
    bool Frame();
    bool Resize(UINT width, UINT height);
    void ReleaseDevice();

    Camera* m_pCamera = nullptr;
private:
    HRESULT SetupBackBuffer();
    HRESULT InitScene();
    void HandleMovementInput();

    ID3D11Buffer* m_pWorldMatrixBuffer = nullptr;
    ID3D11Buffer* m_pSceneMatrixBuffer = nullptr;
    ID3D11RasterizerState* m_pRasterizerState = nullptr;
    ID3D11Device* m_pDevice = nullptr;
    ID3D11DeviceContext* m_pDeviceContext = nullptr;
    IDXGISwapChain* m_pSwapChain = nullptr;
    ID3D11RenderTargetView* m_pBackBufferRTV = nullptr;
    ID3D11Buffer* m_pVertexBuffer = nullptr;
    ID3D11Buffer* m_pIndexBuffer = nullptr;
    ID3D11InputLayout* m_pInputLayout = nullptr;
    ID3D11VertexShader* m_pVertexShader = nullptr;
    ID3D11PixelShader* m_pPixelShader = nullptr;
    UINT m_width = 0;
    UINT m_height = 0;

    Input* m_pInput = nullptr;
};