#pragma once
#include <wrl.h>
#include <d3d12.h>
#include <dxgi1_4.h>

using namespace Microsoft::WRL;
class Communicator;
class DXGfxCore
{
public:
    DXGfxCore(Communicator*);
	bool Init( HWND );
	HRESULT CreateDevice();
	HRESULT Resize( uint16_t, uint16_t );
	void Update();
	void Render();
	void Release();
	void Destory();

	HRESULT DXTrace( const char*, DWORD, HRESULT, const char* );
	void  DXTrace( const char*, DWORD, const char* );

private:
	void WaitForCommandQueue( ID3D12CommandQueue* );
	HWND								hwnd;
	HANDLE								hFenceEvent;

	ComPtr<ID3D12Device>				dxDevice;
	ComPtr<ID3D12CommandQueue>			cmdQueue;
	ComPtr<ID3D12CommandAllocator>		cmdAllocator;
	ComPtr<ID3D12GraphicsCommandList>	cmdList;
	ComPtr<IDXGISwapChain3>				swapChain;
	ComPtr<ID3D12Fence>					queueFence;
	ComPtr<IDXGIFactory3>				dxgiFactory;
	ComPtr<ID3D12DescriptorHeap>		descriptorHeapRTV;
	ComPtr<ID3D12Resource>				renderTarget[2];
	ComPtr<ID3D12Resource>				renderTargetDepth;
	ComPtr<ID3D12RootSignature>			rootSignature;
	ComPtr<ID3D12PipelineState>			pipelineState;
	ComPtr<ID3D12DescriptorHeap>		descriptorHeapCB;
	ComPtr<ID3D12DescriptorHeap>		descriptorHeapDSB;
	ComPtr<ID3D12Resource>				vertexBuffer;
	ComPtr<ID3D12Resource>				indexBuffer;
	ComPtr<ID3D12Resource>				constantBuffer;
	D3D12_VERTEX_BUFFER_VIEW			vertexView;
	D3D12_INDEX_BUFFER_VIEW				indexView;

	D3D12_CPU_DESCRIPTOR_HANDLE			handleRTV[2];
	D3D12_CPU_DESCRIPTOR_HANDLE			handleDSV;

	DXGI_SWAP_CHAIN_DESC				descSwapChain;
	D3D12_VIEWPORT						viewPort;
	D3D12_RECT							viewRect;

	uint16_t							windowWidth;
	uint16_t							windowHeight;

    Communicator*                       communicator;
};
