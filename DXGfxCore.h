#pragma once
#include <wrl.h>
#include <d3d12.h>
#include <dxgi1_4.h>

using namespace Microsoft::WRL;
class DXGfxCore
{
public:
	DXGfxCore();
	bool Init(HWND);
	bool CreateDevice();
	bool Resize();
	void Update();
	void Render();
	void Release();
	void Destory();

private:
	void WaitForCommandQueue(ID3D12CommandQueue*);
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

	uint16_t							windowWidth;
	uint16_t							windowHeight;
};