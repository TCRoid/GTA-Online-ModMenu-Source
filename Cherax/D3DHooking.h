#pragma once
#include <stdint.h>
#include <memory>

#include "gui.h"
#include "function_types.h"

#define DbgMessages 1 // 1 to enable dbg messages




namespace DX {

	enum D3DVersions
	{
		autoDetect,
		D3D9,
		D3D10,
		D3D11,
		D3D12
	};
	

	class D3DHooking
	{
	public:
		explicit D3DHooking(int D3DXX = 0);
		~D3DHooking();

		int getRenderType();
		static uintptr_t* get_methodes_table();

	public:
		int g_renderType{};
		uintptr_t* g_methodsTable{};
	};

	template <typename T>
	using comptr = Microsoft::WRL::ComPtr<T>;

	class DX11Renderer
	{
	public:
		explicit DX11Renderer();
		~DX11Renderer();

		static LRESULT wndproc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
		WNDPROC oWndproc = NULL;

		void pre_reset();
		void post_reset();

		void resizeImGui();

		static HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
		static HRESULT __stdcall hkResizebuffers(IDXGISwapChain* pSwapChain, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags);

		functions::DX11Present oPresent{};
		functions::DX11ResizeBuffers oResizebuffers{};

	public:
		comptr<ID3D11Device> m_d3d_device;
		comptr<ID3D11DeviceContext> m_d3d_device_context;
	};
}

inline DX::D3DHooking* g_d3dHooking{};
inline DX::DX11Renderer* g_renderer{};

/*class DX12Renderer
{
public:
	explicit DX12Renderer();
	~DX12Renderer();

	static LRESULT wndproc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
	WNDPROC oWndproc = NULL;

	void pre_reset();
	void post_reset();

	static HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
	static HRESULT __stdcall hkResizebuffers(IDXGISwapChain* pSwapChain, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags);
	static void __stdcall hkDrawInstanced(ID3D12GraphicsCommandList* dCommandList, UINT VertexCountPerInstance, UINT InstanceCount, UINT StartVertexLocation, UINT StartInstanceLocation);
	static void __stdcall hkSetDescriptorHeaps(ID3D12GraphicsCommandList* dCommandList, UINT NumDescriptorHeaps, ID3D12DescriptorHeap* const* ppDescriptorHeaps);
	static void __stdcall hkResourceBarrier(ID3D12GraphicsCommandList* dCommandList, UINT NumBarriers, const D3D12_RESOURCE_BARRIER* pBarriers);


	functions::DX12Present oPresent = NULL;
	functions::DX12ResizeBuffers oResizebuffers = NULL;
	functions::DX12DrawInstanced oDrawInstanced = NULL;
	functions::DX12SetDescriptorHeaps oSetDescriptorHeaps = NULL;
	functions::DX12ResourceBarrier oResourceBarrier = NULL;

public:
	uint64_t* g_methodsTable{ nullptr };
	ID3D12Device* pDevice{ nullptr };
	ID3D12GraphicsCommandList* pGraphicsCmd{ nullptr };
	ID3D12DescriptorHeap* pDescriptorHeap{ nullptr };
};
inline DX12Renderer* g_renderer{};*/

/*
D3D9 Methods Table:
[0]   QueryInterface
[1]   AddRef
[2]   Release
[3]   TestCooperativeLevel
[4]   GetAvailableTextureMem
[5]   EvictManagedResources
[6]   GetDirect3D
[7]   GetDeviceCaps
[8]   GetDisplayMode
[9]   GetCreationParameters
[10]  SetCursorProperties
[11]  SetCursorPosition
[12]  ShowCursor
[13]  CreateAdditionalSwapChain
[14]  GetSwapChain
[15]  GetNumberOfSwapChains
[16]  Reset
[17]  Present
[18]  GetBackBuffer
[19]  GetRasterStatus
[20]  SetDialogBoxMode
[21]  SetGammaRamp
[22]  GetGammaRamp
[23]  CreateTexture
[24]  CreateVolumeTexture
[25]  CreateCubeTexture
[26]  CreateVertexBuffer
[27]  CreateIndexBuffer
[28]  CreateRenderTarget
[29]  CreateDepthStencilSurface
[30]  UpdateSurface
[31]  UpdateTexture
[32]  GetRenderTargetData
[33]  GetFrontBufferData
[34]  StretchRect
[35]  ColorFill
[36]  CreateOffscreenPlainSurface
[37]  SetRenderTarget
[38]  GetRenderTarget
[39]  SetDepthStencilSurface
[40]  GetDepthStencilSurface
[41]  BeginScene
[42]  EndScene
[43]  Clear
[44]  SetTransform
[45]  GetTransform
[46]  MultiplyTransform
[47]  SetViewport
[48]  GetViewport
[49]  SetMaterial
[50]  GetMaterial
[51]  SetLight
[52]  GetLight
[53]  LightEnable
[54]  GetLightEnable
[55]  SetClipPlane
[56]  GetClipPlane
[57]  SetRenderState
[58]  GetRenderState
[59]  CreateStateBlock
[60]  BeginStateBlock
[61]  EndStateBlock
[62]  SetClipStatus
[63]  GetClipStatus
[64]  GetTexture
[65]  SetTexture
[66]  GetTextureStageState
[67]  SetTextureStageState
[68]  GetSamplerState
[69]  SetSamplerState
[70]  ValidateDevice
[71]  SetPaletteEntries
[72]  GetPaletteEntries
[73]  SetCurrentTexturePalette
[74]  GetCurrentTexturePalette
[75]  SetScissorRect
[76]  GetScissorRect
[77]  SetSoftwareVertexProcessing
[78]  GetSoftwareVertexProcessing
[79]  SetNPatchMode
[80]  GetNPatchMode
[81]  DrawPrimitive
[82]  DrawIndexedPrimitive
[83]  DrawPrimitiveUP
[84]  DrawIndexedPrimitiveUP
[85]  ProcessVertices
[86]  CreateVertexDeclaration
[87]  SetVertexDeclaration
[88]  GetVertexDeclaration
[89]  SetFVF
[90]  GetFVF
[91]  CreateVertexShader
[92]  SetVertexShader
[93]  GetVertexShader
[94]  SetVertexShaderConstantF
[95]  GetVertexShaderConstantF
[96]  SetVertexShaderConstantI
[97]  GetVertexShaderConstantI
[98]  SetVertexShaderConstantB
[99]  GetVertexShaderConstantB
[100] SetStreamSource
[101] GetStreamSource
[102] SetStreamSourceFreq
[103] GetStreamSourceFreq
[104] SetIndices
[105] GetIndices
[106] CreatePixelShader
[107] SetPixelShader
[108] GetPixelShader
[109] SetPixelShaderConstantF
[110] GetPixelShaderConstantF
[111] SetPixelShaderConstantI
[112] GetPixelShaderConstantI
[113] SetPixelShaderConstantB
[114] GetPixelShaderConstantB
[115] DrawRectPatch
[116] DrawTriPatch
[117] DeletePatch
[118] CreateQuery

D3D10 Methods Table:
[0]   QueryInterface
[1]   AddRef
[2]   Release
[3]   SetPrivateData
[4]   SetPrivateDataInterface
[5]   GetPrivateData
[6]   GetParent
[7]   GetDevice
[8]   Present
[9]   GetBuffer
[10]  SetFullscreenState
[11]  GetFullscreenState
[12]  GetDesc
[13]  ResizeBuffers
[14]  ResizeTarget
[15]  GetContainingOutput
[16]  GetFrameStatistics
[17]  GetLastPresentCount
[18]  QueryInterface
[19]  AddRef
[20]  Release
[21]  VSSetConstantBuffers
[22]  PSSetShaderResources
[23]  PSSetShader
[24]  PSSetSamplers
[25]  VSSetShader
[26]  DrawIndexed
[27]  Draw
[28]  PSSetConstantBuffers
[29]  IASetInputLayout
[30]  IASetVertexBuffers
[31]  IASetIndexBuffer
[32]  DrawIndexedInstanced
[33]  DrawInstanced
[34]  GSSetConstantBuffers
[35]  GSSetShader
[36]  IASetPrimitiveTopology
[37]  VSSetShaderResources
[38]  VSSetSamplers
[39]  SetPredication
[40]  GSSetShaderResources
[41]  GSSetSamplers
[42]  OMSetRenderTargets
[43]  OMSetBlendState
[44]  OMSetDepthStencilState
[45]  SOSetTargets
[46]  DrawAuto
[47]  RSSetState
[48]  RSSetViewports
[49]  RSSetScissorRects
[50]  CopySubresourceRegion
[51]  CopyResource
[52]  UpdateSubresource
[53]  ClearRenderTargetView
[54]  ClearDepthStencilView
[55]  GenerateMips
[56]  ResolveSubresource
[57]  VSGetConstantBuffers
[58]  PSGetShaderResources
[59]  PSGetShader
[60]  PSGetSamplers
[61]  VSGetShader
[62]  PSGetConstantBuffers
[63]  IAGetInputLayout
[64]  IAGetVertexBuffers
[65]  IAGetIndexBuffer
[66]  GSGetConstantBuffers
[67]  GSGetShader
[68]  IAGetPrimitiveTopology
[69]  VSGetShaderResources
[70]  VSGetSamplers
[71]  GetPredication
[72]  GSGetShaderResources
[73]  GSGetSamplers
[74]  OMGetRenderTargets
[75]  OMGetBlendState
[76]  OMGetDepthStencilState
[77]  SOGetTargets
[78]  RSGetState
[79]  RSGetViewports
[80]  RSGetScissorRects
[81]  GetDeviceRemovedReason
[82]  SetExceptionMode
[83]  GetExceptionMode
[84]  GetPrivateData
[85]  SetPrivateData
[86]  SetPrivateDataInterface
[87]  ClearState
[88]  Flush
[89]  CreateBuffer
[90]  CreateTexture1D
[91]  CreateTexture2D
[92]  CreateTexture3D
[93]  CreateShaderResourceView
[94]  CreateRenderTargetView
[95]  CreateDepthStencilView
[96]  CreateInputLayout
[97]  CreateVertexShader
[98]  CreateGeometryShader
[99]  CreateGemoetryShaderWithStreamOutput
[100] CreatePixelShader
[101] CreateBlendState
[102] CreateDepthStencilState
[103] CreateRasterizerState
[104] CreateSamplerState
[105] CreateQuery
[106] CreatePredicate
[107] CreateCounter
[108] CheckFormatSupport
[109] CheckMultisampleQualityLevels
[110] CheckCounterInfo
[111] CheckCounter
[112] GetCreationFlags
[113] OpenSharedResource
[114] SetTextFilterSize
[115] GetTextFilterSize

D3D11 Methods Table:
[0]   QueryInterface
[1]   AddRef
[2]   Release
[3]   SetPrivateData
[4]   SetPrivateDataInterface
[5]   GetPrivateData
[6]   GetParent
[7]   GetDevice
[8]   Present
[9]   GetBuffer
[10]  SetFullscreenState
[11]  GetFullscreenState
[12]  GetDesc
[13]  ResizeBuffers
[14]  ResizeTarget
[15]  GetContainingOutput
[16]  GetFrameStatistics
[17]  GetLastPresentCount
[18]  QueryInterface
[19]  AddRef
[20]  Release
[21]  CreateBuffer
[22]  CreateTexture1D
[23]  CreateTexture2D
[24]  CreateTexture3D
[25]  CreateShaderResourceView
[26]  CreateUnorderedAccessView
[27]  CreateRenderTargetView
[28]  CreateDepthStencilView
[29]  CreateInputLayout
[30]  CreateVertexShader
[31]  CreateGeometryShader
[32]  CreateGeometryShaderWithStreamOutput
[33]  CreatePixelShader
[34]  CreateHullShader
[35]  CreateDomainShader
[36]  CreateComputeShader
[37]  CreateClassLinkage
[38]  CreateBlendState
[39]  CreateDepthStencilState
[40]  CreateRasterizerState
[41]  CreateSamplerState
[42]  CreateQuery
[43]  CreatePredicate
[44]  CreateCounter
[45]  CreateDeferredContext
[46]  OpenSharedResource
[47]  CheckFormatSupport
[48]  CheckMultisampleQualityLevels
[49]  CheckCounterInfo
[50]  CheckCounter
[51]  CheckFeatureSupport
[52]  GetPrivateData
[53]  SetPrivateData
[54]  SetPrivateDataInterface
[55]  GetFeatureLevel
[56]  GetCreationFlags
[57]  GetDeviceRemovedReason
[58]  GetImmediateContext
[59]  SetExceptionMode
[60]  GetExceptionMode
[61]  QueryInterface
[62]  AddRef
[63]  Release
[64]  GetDevice
[65]  GetPrivateData
[66]  SetPrivateData
[67]  SetPrivateDataInterface
[68]  SetConstantBuffers
[69]  SetShaderResources
[70]  SetShader
[71]  SetSamplers
[72]  SetShader
[73]  DrawIndexed
[74]  Draw
[75]  Map
[76]  Unmap
[77]  SetConstantBuffers
[78]  IASetInputLayout
[79]  IASetVertexBuffers
[80]  IASetIndexBuffer
[81]  DrawIndexedInstanced
[82]  DrawInstanced
[83]  SetConstantBuffers
[84]  SetShader
[85]  IASetPrimitiveTopology
[86]  SetShaderResources
[87]  SetSamplers
[88]  Begin
[89]  End
[90]  GetData
[91]  SetPredication
[92]  SetShaderResources
[93]  SetSamplers
[94]  OMSetRenderTargets
[95]  OMSetRenderTargetsAndUnorderedAccessViews
[96]  OMSetBlendState
[97]  OMSetDepthStencilState
[98]  SOSetTargets
[99]  DrawAuto
[100] DrawIndexedInstancedIndirect
[101] DrawInstancedIndirect
[102] Dispatch
[103] DispatchIndirect
[104] RSSetState
[105] RSSetViewports
[106] RSSetScissorRects
[107] CopySubresourceRegion
[108] CopyResource
[109] UpdateSubresource
[110] CopyStructureCount
[111] ClearRenderTargetView
[112] ClearUnorderedAccessViewUint
[113] ClearUnorderedAccessViewFloat
[114] ClearDepthStencilView
[115] GenerateMips
[116] SetResourceMinLOD
[117] GetResourceMinLOD
[118] ResolveSubresource
[119] ExecuteCommandList
[120] SetShaderResources
[121] SetShader
[122] SetSamplers
[123] SetConstantBuffers
[124] SetShaderResources
[125] SetShader
[126] SetSamplers
[127] SetConstantBuffers
[128] SetShaderResources
[129] CSSetUnorderedAccessViews
[130] SetShader
[131] SetSamplers
[132] SetConstantBuffers
[133] VSGetConstantBuffers
[134] PSGetShaderResources
[135] PSGetShader
[136] PSGetSamplers
[137] VSGetShader
[138] PSGetConstantBuffers
[139] IAGetInputLayout
[140] IAGetVertexBuffers
[141] IAGetIndexBuffer
[142] GSGetConstantBuffers
[143] GSGetShader
[144] IAGetPrimitiveTopology
[145] VSGetShaderResources
[146] VSGetSamplers
[147] GetPredication
[148] GSGetShaderResources
[149] GSGetSamplers
[150] OMGetRenderTargets
[151] OMGetRenderTargetsAndUnorderedAccessViews
[152] OMGetBlendState
[153] OMGetDepthStencilState
[154] SOGetTargets
[155] RSGetState
[156] RSGetViewports
[157] RSGetScissorRects
[158] HSGetShaderResources
[159] HSGetShader
[160] HSGetSamplers
[161] HSGetConstantBuffers
[162] DSGetShaderResources
[163] DSGetShader
[164] DSGetSamplers
[165] DSGetConstantBuffers
[166] CSGetShaderResources
[167] CSGetUnorderedAccessViews
[168] CSGetShader
[169] CSGetSamplers
[170] CSGetConstantBuffers
[171] ClearState
[172] Flush
[173] GetType
[174] GetContextFlags
[175] FinishCommandList
[176] CopySubresourceRegion1
[177] UpdateSubresource1
[178] DiscardResource
[179] DiscardView
[180] SetConstantBuffers1
[181] SetConstantBuffers1
[182] SetConstantBuffers1
[183] SetConstantBuffers1
[184] SetConstantBuffers1
[185] SetConstantBuffers1
[186] VSGetConstantBuffers1
[187] HSGetConstantBuffers1
[188] DSGetConstantBuffers1
[189] GSGetConstantBuffers1
[190] PSGetConstantBuffers1
[191] CSGetConstantBuffers1
[192] SwapDeviceContextState
[193] ClearView
[194] DiscardView1
[195] UpdateTileMappings
[196] CopyTileMappings
[197] CopyTiles
[198] UpdateTiles
[199] ResizeTilePool
[200] TiledResourceBarrier
[201] IsAnnotationEnabled
[202] SetMarkerInt
[203] BeginEventInt
[204] EndEvent

D3D12 Methods Table:
[0]   QueryInterface
[1]   AddRef
[2]   Release
[3]   GetPrivateData
[4]   SetPrivateData
[5]   SetPrivateDataInterface
[6]   SetName
[7]   GetNodeCount
[8]   CreateCommandQueue
[9]   CreateCommandAllocator
[10]  CreateGraphicsPipelineState
[11]  CreateComputePipelineState
[12]  CreateCommandList
[13]  CheckFeatureSupport
[14]  CreateDescriptorHeap
[15]  GetDescriptorHandleIncrementSize
[16]  CreateRootSignature
[17]  CreateConstantBufferView
[18]  CreateShaderResourceView
[19]  CreateUnorderedAccessView
[20]  CreateRenderTargetView
[21]  CreateDepthStencilView
[22]  CreateSampler
[23]  CopyDescriptors
[24]  CopyDescriptorsSimple
[25]  GetResourceAllocationInfo
[26]  GetCustomHeapProperties
[27]  CreateCommittedResource
[28]  CreateHeap
[29]  CreatePlacedResource
[30]  CreateReservedResource
[31]  CreateSharedHandle
[32]  OpenSharedHandle
[33]  OpenSharedHandleByName
[34]  MakeResident
[35]  Evict
[36]  CreateFence
[37]  GetDeviceRemovedReason
[38]  GetCopyableFootprints
[39]  CreateQueryHeap
[40]  SetStablePowerState
[41]  CreateCommandSignature
[42]  GetResourceTiling
[43]  GetAdapterLuid
[44]  QueryInterface
[45]  AddRef
[46]  Release
[47]  GetPrivateData
[48]  SetPrivateData
[49]  SetPrivateDataInterface
[50]  SetName
[51]  GetDevice
[52]  UpdateTileMappings
[53]  CopyTileMappings
[54]  ExecuteCommandLists
[55]  SetMarker
[56]  BeginEvent
[57]  EndEvent
[58]  Signal
[59]  Wait
[60]  GetTimestampFrequency
[61]  GetClockCalibration
[62]  GetDesc
[63]  QueryInterface
[64]  AddRef
[65]  Release
[66]  GetPrivateData
[67]  SetPrivateData
[68]  SetPrivateDataInterface
[69]  SetName
[70]  GetDevice
[71]  Reset
[72]  QueryInterface
[73]  AddRef
[74]  Release
[75]  GetPrivateData
[76]  SetPrivateData
[77]  SetPrivateDataInterface
[78]  SetName
[79]  GetDevice
[80]  GetType
[81]  Close
[82]  Reset
[83]  ClearState
[84]  DrawInstanced
[85]  DrawIndexedInstanced
[86]  Dispatch
[87]  CopyBufferRegion
[88]  CopyTextureRegion
[89]  CopyResource
[90]  CopyTiles
[91]  ResolveSubresource
[92]  IASetPrimitiveTopology
[93]  RSSetViewports
[94]  RSSetScissorRects
[95]  OMSetBlendFactor
[96]  OMSetStencilRef
[97]  SetPipelineState
[98]  ResourceBarrier
[99]  ExecuteBundle
[100] SetDescriptorHeaps
[101] SetComputeRootSignature
[102] SetGraphicsRootSignature
[103] SetComputeRootDescriptorTable
[104] SetGraphicsRootDescriptorTable
[105] SetComputeRoot32BitConstant
[106] SetGraphicsRoot32BitConstant
[107] SetComputeRoot32BitConstants
[108] SetGraphicsRoot32BitConstants
[109] SetComputeRootConstantBufferView
[110] SetGraphicsRootConstantBufferView
[111] SetComputeRootShaderResourceView
[112] SetGraphicsRootShaderResourceView
[113] SetComputeRootUnorderedAccessView
[114] SetGraphicsRootUnorderedAccessView
[115] IASetIndexBuffer
[116] IASetVertexBuffers
[117] SOSetTargets
[118] OMSetRenderTargets
[119] ClearDepthStencilView
[120] ClearRenderTargetView
[121] ClearUnorderedAccessViewUint
[122] ClearUnorderedAccessViewFloat
[123] DiscardResource
[124] BeginQuery
[125] EndQuery
[126] ResolveQueryData
[127] SetPredication
[128] SetMarker
[129] BeginEvent
[130] EndEvent
[131] ExecuteIndirect
[132] QueryInterface
[133] AddRef
[134] Release
[135] SetPrivateData
[136] SetPrivateDataInterface
[137] GetPrivateData
[138] GetParent
[139] GetDevice
[140] Present
[141] GetBuffer
[142] SetFullscreenState
[143] GetFullscreenState
[144] GetDesc
[145] ResizeBuffers
[146] ResizeTarget
[147] GetContainingOutput
[148] GetFrameStatistics
[149] GetLastPresentCount
*/