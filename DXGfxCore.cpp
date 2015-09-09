#include <iostream>
#include <DirectXMath.h>
#include "DXGfxCore.h"

#include "Communicator.h"

#pragma comment( lib, "d3d12.lib" )
#pragma comment(lib, "dxgi.lib")

#define DEBUG

#if defined(DEBUG) || defined(_DEBUG)
#ifndef V
#define V(x)           { hr = (x); if( FAILED(hr) ) { DXTrace( __FILE__, (DWORD)__LINE__, hr, #x); } }
#endif //#ifndef V
#ifndef VRET
#define VRET(x)           { hr = (x); if( FAILED(hr) ) { return DXTrace( __FILE__, (DWORD)__LINE__, hr, #x); } }
#endif //#ifndef VRET
#else
#ifndef V
#define V(x)           { hr = (x); }
#endif //#ifndef V
#ifndef VRET
#define VRET(x)           { hr = (x); if( FAILED(hr) ) { return hr; } }
#endif //#ifndef VRET
#endif //#if defined(DEBUG) || defined(_DEBUG)

HRESULT DXGfxCore::DXTrace( const char* strFile, DWORD dwLine, HRESULT hr, const char* strMsg )
{
    QString errorMsg;
	if( strFile )
		errorMsg.append(QString("%1@%2").arg(QString::number(dwLine),QString(strFile)));
	size_t nMsgLen = ( strMsg ) ? strnlen_s( strMsg, 1024 ) : 0;
	if ( nMsgLen > 0 )
		errorMsg.append( QString( " Calling: %1 failed!\n" ).arg( strMsg ));
    communicator->printMessage(errorMsg,Communicator::MSG_ERROR);
	return hr;
}

void DXGfxCore::DXTrace( const char* strFile, DWORD dwLine, const char* strMsg )
{
    QString errorMsg;
	if ( strFile )
		errorMsg.append( QString( "%1@%2" ).arg( QString::number( dwLine ), QString( strFile ) ) );
	size_t nMsgLen = ( strMsg ) ? strnlen_s( strMsg, 1024 ) : 0;
	if ( nMsgLen > 0 )
		errorMsg.append( QString( strMsg ) );
    communicator->printMessage(errorMsg,Communicator::MSG_ERROR );
}

using namespace DirectX;

struct Vertex
{
	XMFLOAT3 Pos;
	XMFLOAT3 Col;
};

struct DXBolb
{
	long size;
	void* ptr;
};

DXBolb gVS;
DXBolb gPS;

Vertex cubeVertices[] =
{
	{ XMFLOAT3( -1.0f, -1.0f, -1.0f ), XMFLOAT3( 0.0f, 0.0f, 0.0f ) },
	{ XMFLOAT3( -1.0f, -1.0f,  1.0f ), XMFLOAT3( 0.0f, 0.0f, 1.0f ) },
	{ XMFLOAT3( -1.0f,  1.0f, -1.0f ), XMFLOAT3( 0.0f, 1.0f, 0.0f ) },
	{ XMFLOAT3( -1.0f,  1.0f,  1.0f ), XMFLOAT3( 0.0f, 1.0f, 1.0f ) },
	{ XMFLOAT3( 1.0f, -1.0f, -1.0f ), XMFLOAT3( 1.0f, 0.0f, 0.0f ) },
	{ XMFLOAT3( 1.0f, -1.0f,  1.0f ), XMFLOAT3( 1.0f, 0.0f, 1.0f ) },
	{ XMFLOAT3( 1.0f,  1.0f, -1.0f ), XMFLOAT3( 1.0f, 1.0f, 0.0f ) },
	{ XMFLOAT3( 1.0f,  1.0f,  1.0f ), XMFLOAT3( 1.0f, 1.0f, 1.0f ) },
};

uint16_t cubeIndices[] =
{
	0,2,1, 1,2,3,  4,5,6, 5,7,6,  0,1,5, 0,5,4,  2,6,7, 2,7,3,  0,4,6, 0,6,2,  1,3,7, 1,7,5,
};

// Helper Functions
void SetResourceBarrier( ID3D12GraphicsCommandList* commandList, ID3D12Resource* resource, D3D12_RESOURCE_STATES before, D3D12_RESOURCE_STATES after )
{
	D3D12_RESOURCE_BARRIER descBarrier;
	ZeroMemory( &descBarrier, sizeof( descBarrier ) );
	descBarrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
	descBarrier.Transition.pResource = resource;
	descBarrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
	descBarrier.Transition.StateBefore = before;
	descBarrier.Transition.StateAfter = after;
	commandList->ResourceBarrier( 1, &descBarrier );
}

void DXGfxCore::WaitForCommandQueue( ID3D12CommandQueue* pCommandQueue ) {
	static UINT64 frames = 0;
	queueFence->SetEventOnCompletion( frames, hFenceEvent );
	pCommandQueue->Signal( queueFence.Get(), frames );
	WaitForSingleObject( hFenceEvent, INFINITE );
	frames++;
}

D3D12_GRAPHICS_PIPELINE_STATE_DESC CreateGraphicsPipelineStateDesc( ID3D12RootSignature * pRootSignature, const void * pBinaryVS, int vsSize, const void * pBinaryPS, int psSize, D3D12_INPUT_ELEMENT_DESC * descInputElements, int numInputElements )
{
	D3D12_GRAPHICS_PIPELINE_STATE_DESC descState;
	ZeroMemory( &descState, sizeof( descState ) );
	descState.VS.pShaderBytecode = pBinaryVS;
	descState.VS.BytecodeLength = vsSize;
	descState.PS.pShaderBytecode = pBinaryPS;
	descState.PS.BytecodeLength = psSize;
	descState.SampleDesc.Count = 1;
	descState.SampleMask = UINT_MAX;
	descState.InputLayout.pInputElementDescs = descInputElements;
	descState.InputLayout.NumElements = numInputElements;
	descState.pRootSignature = pRootSignature;
	descState.NumRenderTargets = 1;
	descState.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
	descState.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
	descState.RasterizerState.CullMode = D3D12_CULL_MODE_NONE;
	descState.RasterizerState.FillMode = D3D12_FILL_MODE_SOLID;
	descState.RasterizerState.DepthClipEnable = TRUE;
	descState.RasterizerState.ConservativeRaster = D3D12_CONSERVATIVE_RASTERIZATION_MODE_OFF;
	for ( int i = 0; i < _countof( descState.BlendState.RenderTarget ); ++i ) {
		descState.BlendState.RenderTarget[i].BlendEnable = FALSE;
		descState.BlendState.RenderTarget[i].SrcBlend = D3D12_BLEND_ONE;
		descState.BlendState.RenderTarget[i].DestBlend = D3D12_BLEND_ZERO;
		descState.BlendState.RenderTarget[i].BlendOp = D3D12_BLEND_OP_ADD;
		descState.BlendState.RenderTarget[i].SrcBlendAlpha = D3D12_BLEND_ONE;
		descState.BlendState.RenderTarget[i].DestBlendAlpha = D3D12_BLEND_ZERO;
		descState.BlendState.RenderTarget[i].BlendOpAlpha = D3D12_BLEND_OP_ADD;
		descState.BlendState.RenderTarget[i].RenderTargetWriteMask = D3D12_COLOR_WRITE_ENABLE_ALL;
	}
	descState.DepthStencilState.DepthEnable = FALSE;
	return descState;
}

ComPtr<ID3D12Resource> CreateVertexBuffer(
	ID3D12Device* device, int bufferSize, D3D12_HEAP_TYPE type, D3D12_RESOURCE_STATES states )
{
	D3D12_HEAP_PROPERTIES heapProps;
	D3D12_RESOURCE_DESC   descResourceVB;
	ZeroMemory( &heapProps, sizeof( heapProps ) );
	ZeroMemory( &descResourceVB, sizeof( descResourceVB ) );
	heapProps.Type = type;
	heapProps.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
	heapProps.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
	heapProps.CreationNodeMask = 0;
	heapProps.VisibleNodeMask = 0;
	descResourceVB.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
	descResourceVB.Width = bufferSize;
	descResourceVB.Height = 1;
	descResourceVB.DepthOrArraySize = 1;
	descResourceVB.MipLevels = 1;
	descResourceVB.Format = DXGI_FORMAT_UNKNOWN;
	descResourceVB.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
	descResourceVB.SampleDesc.Count = 1;

	ComPtr<ID3D12Resource> vertexBuffer;
	HRESULT hr;
	device->CreateCommittedResource(
		&heapProps,
		D3D12_HEAP_FLAG_NONE,
		&descResourceVB,
		states,
		nullptr,
		IID_PPV_ARGS( vertexBuffer.GetAddressOf() )
		);
	
	return vertexBuffer;
}

ComPtr<ID3D12Resource> CreateIndexBuffer( ID3D12Device * device, int bufferSize, D3D12_HEAP_TYPE type, D3D12_RESOURCE_STATES states )
{
	D3D12_HEAP_PROPERTIES heapProps;
	D3D12_RESOURCE_DESC   descResourceIB;
	ZeroMemory( &heapProps, sizeof( heapProps ) );
	ZeroMemory( &descResourceIB, sizeof( descResourceIB ) );
	heapProps.Type = type;
	heapProps.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
	heapProps.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
	heapProps.CreationNodeMask = 0;
	heapProps.VisibleNodeMask = 0;
	descResourceIB.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
	descResourceIB.Width = bufferSize;
	descResourceIB.Height = 1;
	descResourceIB.DepthOrArraySize = 1;
	descResourceIB.MipLevels = 1;
	descResourceIB.Format = DXGI_FORMAT_UNKNOWN;
	descResourceIB.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
	descResourceIB.SampleDesc.Count = 1;

	ComPtr<ID3D12Resource> indexBuffer;
	HRESULT hr;
	device->CreateCommittedResource(
		&heapProps,
		D3D12_HEAP_FLAG_NONE,
		&descResourceIB,
		states,
		nullptr,
		IID_PPV_ARGS( indexBuffer.GetAddressOf() )
		);
	
	return indexBuffer;
}

ComPtr<ID3D12Resource> CreateConstantBuffer( ID3D12Device * device, int bufferSize )
{
	ComPtr<ID3D12Resource> cbBuffer;
	D3D12_HEAP_PROPERTIES heapProps;
	D3D12_RESOURCE_DESC   descResourceVB;
	ZeroMemory( &heapProps, sizeof( heapProps ) );
	ZeroMemory( &descResourceVB, sizeof( descResourceVB ) );
	heapProps.Type = D3D12_HEAP_TYPE_UPLOAD;
	heapProps.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
	heapProps.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
	heapProps.CreationNodeMask = 0;
	heapProps.VisibleNodeMask = 0;
	descResourceVB.Dimension = D3D12_RESOURCE_DIMENSION_BUFFER;
	descResourceVB.Width = bufferSize;
	descResourceVB.Height = 1;
	descResourceVB.DepthOrArraySize = 1;
	descResourceVB.MipLevels = 1;
	descResourceVB.Format = DXGI_FORMAT_UNKNOWN;
	descResourceVB.Layout = D3D12_TEXTURE_LAYOUT_ROW_MAJOR;
	descResourceVB.SampleDesc.Count = 1;

	HRESULT hr;
	device->CreateCommittedResource(
		&heapProps,
		D3D12_HEAP_FLAG_NONE,
		&descResourceVB,
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS( cbBuffer.GetAddressOf() )
		);
	return cbBuffer;
}

ComPtr<ID3D12Resource> CreateDepthBuffer( ID3D12Device * device, int width, int height )
{
	ComPtr<ID3D12Resource> depthBuffer;
	D3D12_RESOURCE_DESC descDepth;
	ZeroMemory( &descDepth, sizeof( descDepth ) );
	D3D12_HEAP_PROPERTIES heapProps;
	ZeroMemory( &heapProps, sizeof( heapProps ) );
	heapProps.Type = D3D12_HEAP_TYPE_DEFAULT;
	heapProps.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
	heapProps.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
	heapProps.CreationNodeMask = 0;
	heapProps.VisibleNodeMask = 0;
	descDepth.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
	descDepth.Width = width;
	descDepth.Height = height;
	descDepth.DepthOrArraySize = 1;
	descDepth.MipLevels = 0;
	descDepth.Format = DXGI_FORMAT_R32_TYPELESS;
	descDepth.Layout = D3D12_TEXTURE_LAYOUT_UNKNOWN;
	descDepth.SampleDesc.Count = 1;
	descDepth.Flags = D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL;

	D3D12_CLEAR_VALUE dsvClearValue;
	dsvClearValue.Format = DXGI_FORMAT_D32_FLOAT;
	dsvClearValue.DepthStencil.Depth = 1.0f;
	dsvClearValue.DepthStencil.Stencil = 0;
	HRESULT hr;
	device->CreateCommittedResource(
		&heapProps,
		D3D12_HEAP_FLAG_NONE,
		&descDepth,
		D3D12_RESOURCE_STATE_DEPTH_WRITE,
		&dsvClearValue,
		IID_PPV_ARGS( depthBuffer.ReleaseAndGetAddressOf() )
		);
	return depthBuffer;
}


DXGfxCore::DXGfxCore(Communicator* commu)
{
    communicator = commu;
}

bool DXGfxCore::Init( HWND _hwnd )
{
	hwnd = _hwnd;
	windowWidth = 0;
	windowHeight = 0;
	return true;
}

HRESULT DXGfxCore::CreateDevice()
{
	// Create DXGI device
	UINT flagsDXGI = 0;
	ID3D12Debug* debug = nullptr;
	HRESULT hr;
#if 0 || _DEBUG
	D3D12GetDebugInterface( IID_PPV_ARGS( &debug ) );
	if ( debug ) {
		debug->EnableDebugLayer();
		debug->Release();
	}
	flagsDXGI |= DXGI_CREATE_FACTORY_DEBUG;
#endif
	VRET(CreateDXGIFactory2( flagsDXGI, IID_PPV_ARGS( dxgiFactory.ReleaseAndGetAddressOf() ) ));

	// Create DX device
	ComPtr<IDXGIAdapter> adapter;
	VRET(dxgiFactory->EnumAdapters( 0, adapter.GetAddressOf() ));

	VRET(D3D12CreateDevice( adapter.Get(), D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS( dxDevice.GetAddressOf() ) ));

	// Check hardware support
	D3D12_FEATURE_DATA_D3D12_OPTIONS options;
	VRET(dxDevice->CheckFeatureSupport( D3D12_FEATURE_D3D12_OPTIONS, ( void* ) &options, sizeof( options ) ));

	// Create command allocator
	VRET(dxDevice->CreateCommandAllocator( D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS( cmdAllocator.GetAddressOf() ) ));

	// Create command queue
	D3D12_COMMAND_QUEUE_DESC descCommandQueue;
	ZeroMemory( &descCommandQueue, sizeof( descCommandQueue ) );
	descCommandQueue.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
	descCommandQueue.Priority = 0;
	descCommandQueue.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
	VRET(dxDevice->CreateCommandQueue( &descCommandQueue, IID_PPV_ARGS( cmdQueue.GetAddressOf() ) ));

	// Create fence
	hFenceEvent = CreateEvent( NULL, FALSE, FALSE, NULL );
	VRET(dxDevice->CreateFence( 0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS( queueFence.GetAddressOf() ) ));

	// Create swap chain
	ZeroMemory( &descSwapChain, sizeof( descSwapChain ) );
	descSwapChain.BufferCount = 2;
	descSwapChain.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	descSwapChain.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	descSwapChain.OutputWindow = hwnd;
	descSwapChain.SampleDesc.Count = 1;
	descSwapChain.Windowed = TRUE;
	descSwapChain.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;
	descSwapChain.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	VRET(dxgiFactory->CreateSwapChain( cmdQueue.Get(), &descSwapChain, ( IDXGISwapChain** ) swapChain.GetAddressOf() ));

	// Create command list
	VRET(dxDevice->CreateCommandList( 0, D3D12_COMMAND_LIST_TYPE_DIRECT, cmdAllocator.Get(), nullptr, IID_PPV_ARGS( cmdList.GetAddressOf() ) ));

	// Create descriptor heap
	D3D12_DESCRIPTOR_HEAP_DESC descHeap;
	ZeroMemory( &descHeap, sizeof( descHeap ) );
	descHeap.NumDescriptors = 2;
	descHeap.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
	descHeap.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
	VRET(dxDevice->CreateDescriptorHeap( &descHeap, IID_PPV_ARGS( descriptorHeapRTV.GetAddressOf() ) ));

	D3D12_DESCRIPTOR_HEAP_DESC descDescriptorHeapDSB;
	ZeroMemory( &descDescriptorHeapDSB, sizeof( descDescriptorHeapDSB ) );
	descDescriptorHeapDSB.NumDescriptors = 1;
	descDescriptorHeapDSB.Type = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
	descDescriptorHeapDSB.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
	VRET(dxDevice->CreateDescriptorHeap(
		&descDescriptorHeapDSB,
		IID_PPV_ARGS( descriptorHeapDSB.GetAddressOf() ) ));

	// Setup resource
	D3D12_ROOT_SIGNATURE_DESC descRootSignature;
	ZeroMemory( &descRootSignature, sizeof( descRootSignature ) );
	descRootSignature.Flags = D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;
	D3D12_ROOT_PARAMETER rootParameters[1];
	rootParameters[0].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV;
	rootParameters[0].ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL;
	rootParameters[0].Descriptor.ShaderRegister = 0;
	rootParameters[0].Descriptor.RegisterSpace = 0;
	descRootSignature.NumParameters = 1;
	descRootSignature.pParameters = rootParameters;
	ComPtr<ID3DBlob> rootSigBlob, errorBlob;
	VRET(D3D12SerializeRootSignature( &descRootSignature, D3D_ROOT_SIGNATURE_VERSION_1, rootSigBlob.GetAddressOf(), errorBlob.GetAddressOf() ));
	VRET(dxDevice->CreateRootSignature( 0, rootSigBlob->GetBufferPointer(), rootSigBlob->GetBufferSize(), IID_PPV_ARGS( rootSignature.GetAddressOf() ) ));

	FILE* fpVS = nullptr;
	fopen_s( &fpVS, "VertexShader.cso", "rb" );
	if ( !fpVS ) 
	{ 
		DXTrace( __FILE__, ( DWORD ) __LINE__, "Cannot open VertexShader.cso" );
		return E_FAIL;
	}
	fseek( fpVS, 0, SEEK_END );
	gVS.size = ftell( fpVS ); rewind( fpVS );
	gVS.ptr = malloc( gVS.size );
	fread( gVS.ptr, 1, gVS.size, fpVS );
	fclose( fpVS ); fpVS = nullptr;
	FILE* fpPS = nullptr;
	fopen_s( &fpPS, "PixelShader.cso", "rb" );
	if ( !fpPS )
	{
		DXTrace( __FILE__, ( DWORD ) __LINE__, hr, "Cannot open PixelShader.cso" );
		return E_FAIL;
	}
	fseek( fpPS, 0, SEEK_END );
	gPS.size = ftell( fpPS ); rewind( fpPS );
	gPS.ptr = malloc( gPS.size );
	fread( gPS.ptr, 1, gPS.size, fpPS );
	fclose( fpPS ); fpPS = nullptr;

	D3D12_INPUT_ELEMENT_DESC descInputElements[] = {
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
		{ "COLOR",    0, DXGI_FORMAT_R32G32B32_FLOAT, 0,12, D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
	};

	D3D12_GRAPHICS_PIPELINE_STATE_DESC descPipelineState;
	descPipelineState = CreateGraphicsPipelineStateDesc(
		rootSignature.Get(),
		gVS.ptr, gVS.size,
		gPS.ptr, gPS.size,
		descInputElements,
		_countof( descInputElements ) );
	descPipelineState.DepthStencilState.DepthEnable = TRUE;
	descPipelineState.DepthStencilState.DepthFunc = D3D12_COMPARISON_FUNC_LESS_EQUAL;
	descPipelineState.DepthStencilState.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ALL;
	descPipelineState.DSVFormat = DXGI_FORMAT_D32_FLOAT;
	V(dxDevice->CreateGraphicsPipelineState( &descPipelineState, IID_PPV_ARGS( pipelineState.GetAddressOf() ) ));

	vertexBuffer = CreateVertexBuffer(
		dxDevice.Get(),
		sizeof( cubeVertices ),
		D3D12_HEAP_TYPE_UPLOAD,
		D3D12_RESOURCE_STATE_GENERIC_READ );
	if ( !vertexBuffer ) return S_FALSE;

	void* mapped = nullptr;
	VRET(vertexBuffer->Map( 0, nullptr, &mapped ));
	if ( SUCCEEDED( hr ) ) {
		memcpy( mapped, cubeVertices, sizeof( cubeVertices ) );
		vertexBuffer->Unmap( 0, nullptr );
	}

	vertexView.BufferLocation = vertexBuffer->GetGPUVirtualAddress();
	vertexView.StrideInBytes = sizeof( Vertex );
	vertexView.SizeInBytes = sizeof( cubeVertices );

	indexBuffer = CreateIndexBuffer(
		dxDevice.Get(),
		sizeof( cubeIndices ),
		D3D12_HEAP_TYPE_UPLOAD,
		D3D12_RESOURCE_STATE_GENERIC_READ );

	VRET(indexBuffer->Map( 0, nullptr, &mapped ));
	if ( SUCCEEDED( hr ) ) {
		memcpy( mapped, cubeIndices, sizeof( cubeIndices ) );
		indexBuffer->Unmap( 0, nullptr );
	}
	indexView.BufferLocation = indexBuffer->GetGPUVirtualAddress();
	indexView.SizeInBytes = sizeof( cubeIndices );
	indexView.Format = DXGI_FORMAT_R16_UINT;

	constantBuffer = CreateConstantBuffer( dxDevice.Get(), sizeof( XMFLOAT4X4 ) );

	VRET(constantBuffer->Map( 0, nullptr, &mapped ));
	if ( SUCCEEDED( hr ) ) {
		XMFLOAT4X4 mtx;
		XMStoreFloat4x4( &mtx, XMMatrixIdentity() );
		memcpy( mapped, &mtx, sizeof( mtx ) );
		constantBuffer->Unmap( 0, nullptr );
	}
	return TRUE;
}

HRESULT DXGfxCore::Resize( uint16_t width, uint16_t height )
{
	HRESULT hr = S_OK;
	if ( width == windowWidth && height == windowHeight )
		return hr;
	for ( UINT i = 0; i < descSwapChain.BufferCount; ++i ) {
		if ( renderTarget[i].Get() )
			renderTarget[i].Get()->Release();
	}

	windowWidth = width;
	windowHeight = height;

	V(swapChain->ResizeBuffers( descSwapChain.BufferCount, windowWidth,
							  windowHeight, descSwapChain.BufferDesc.Format,
							  descSwapChain.Flags ));

	UINT strideHandleBytes = dxDevice->GetDescriptorHandleIncrementSize( D3D12_DESCRIPTOR_HEAP_TYPE_RTV );
	for ( UINT i = 0; i < descSwapChain.BufferCount; ++i ) {
		VRET(swapChain->GetBuffer( i, IID_PPV_ARGS( renderTarget[i].GetAddressOf() ) ));

		handleRTV[i] = descriptorHeapRTV->GetCPUDescriptorHandleForHeapStart();
		handleRTV[i].ptr += i*strideHandleBytes;
		dxDevice->CreateRenderTargetView( renderTarget[i].Get(), nullptr, handleRTV[i] );
	}

	//renderTargetDepth.~ComPtr ();
	renderTargetDepth.Reset();
	renderTargetDepth = CreateDepthBuffer( dxDevice.Get(), windowWidth, windowHeight );

	D3D12_DEPTH_STENCIL_VIEW_DESC descDSV;
	ZeroMemory( &descDSV, sizeof( descDSV ) );
	descDSV.ViewDimension = D3D12_DSV_DIMENSION_TEXTURE2D;
	descDSV.Format = DXGI_FORMAT_D32_FLOAT;
	descDSV.Texture2D.MipSlice = 0;
	dxDevice->CreateDepthStencilView(
		renderTargetDepth.Get(),
		&descDSV,
		descriptorHeapDSB->GetCPUDescriptorHandleForHeapStart()
		);
	handleDSV = descriptorHeapDSB->GetCPUDescriptorHandleForHeapStart();

	viewPort = { 0.0f, 0.0f, ( float ) windowWidth, ( float ) windowHeight, 0.0f, 1.0f };
	viewRect = { 0, 0, windowWidth, windowHeight };

	//std::cerr << "Back buffer resized to : " << width << "x" << height << "\n";
	communicator->printMessage( QString( "Back buffer resized to: %1x%2" ).arg( QString::number(width), QString::number(height) ) );
	return true;
}

void DXGfxCore::Update()
{

}

void DXGfxCore::Render()
{
	HRESULT hr = S_OK;
	static int count = 0;

	XMMATRIX view = XMMatrixLookAtLH(
		XMVECTOR{ 0.0f, 2.0f, -4.5f },
		XMVECTOR{ 0.0f,0.0f,0.0f },
		XMVECTOR{ 0.0f, 1.0f, 0.0f }
	);
	float fov = XM_PI / 3.0f;
	XMMATRIX proj = XMMatrixPerspectiveFovLH(
		fov,
		float( windowWidth ) / float( windowHeight ),
		0.1f, 100.f
		);

	XMMATRIX world = XMMatrixIdentity();
	world = XMMatrixRotationY( count*0.02f );
	XMMATRIX wvp = XMMatrixMultiply( XMMatrixMultiply( world, view ), proj );
	void* pCB;
	V(constantBuffer->Map( 0, nullptr, &pCB ));
	if ( pCB ) {
		XMStoreFloat4x4( ( XMFLOAT4X4* ) pCB, wvp );
		constantBuffer->Unmap( 0, nullptr );
	}

	//ID3D12DescriptorHeap* heaps[] = { descriptorHeapCB.Get() };

	int targetIndex = swapChain->GetCurrentBackBufferIndex();
	float clearColor[4] = { 0.2f, 0.45f, 0.8f, 0.0f };

	SetResourceBarrier( cmdList.Get(), renderTarget[targetIndex].Get(), D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET );
	cmdList->SetGraphicsRootSignature( rootSignature.Get() );
	cmdList->SetPipelineState( pipelineState.Get() );
	cmdList->SetGraphicsRootConstantBufferView( 0, constantBuffer->GetGPUVirtualAddress() );
	cmdList->RSSetViewports( 1, &viewPort );
	cmdList->RSSetScissorRects( 1, &viewRect );
	cmdList->ClearDepthStencilView( handleDSV, D3D12_CLEAR_FLAG_DEPTH, 1.0f, 0, 0, nullptr );
	cmdList->ClearRenderTargetView( handleRTV[targetIndex], clearColor, 0, nullptr );
	cmdList->OMSetRenderTargets( 1, &handleRTV[targetIndex], TRUE, &handleDSV );

	cmdList->IASetPrimitiveTopology( D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST );
	cmdList->IASetVertexBuffers( 0, 1, &vertexView );
	cmdList->IASetIndexBuffer( &indexView );
	cmdList->DrawIndexedInstanced( 36, 1, 0, 0, 0 );

	SetResourceBarrier( cmdList.Get(), renderTarget[targetIndex].Get(), D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT );
	cmdList->Close();

	ID3D12CommandList* pCommandList = cmdList.Get();
	cmdQueue->ExecuteCommandLists( 1, &pCommandList );
	swapChain->Present( 1, 0 );
	WaitForCommandQueue( cmdQueue.Get() );
	cmdAllocator->Reset();
	cmdList->Reset( cmdAllocator.Get(), nullptr );
	count++;
}

void DXGfxCore::Release()
{

}

void DXGfxCore::Destory()
{
	if ( gVS.ptr ) { free( gVS.ptr ); }
	if ( gPS.ptr ) { free( gPS.ptr ); }
	CloseHandle( hFenceEvent );
}
