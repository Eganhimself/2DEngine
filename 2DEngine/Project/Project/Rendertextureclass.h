#ifndef _RENDERTextureManager_H_
#define _RENDERTextureManager_H_


//////////////
// INCLUDES //
//////////////
#include <d3d11.h>


////////////////////////////////////////////////////////////////////////////////
// Class name: RenderTextureManager
////////////////////////////////////////////////////////////////////////////////
class RenderTextureManager
{
public:
	RenderTextureManager();
	RenderTextureManager(const RenderTextureManager&);
	~RenderTextureManager();

	bool Initialize(ID3D11Device*, int, int);
	void Shutdown();

	void SetRenderTarget(ID3D11DeviceContext*, ID3D11DepthStencilView*);
	void ClearRenderTarget(ID3D11DeviceContext*, ID3D11DepthStencilView*, float, float, float, float);
	ID3D11ShaderResourceView* GetShaderResourceView();

private:
	ID3D11Texture2D* m_renderTargetTexture;
	ID3D11RenderTargetView* m_renderTargetView;
	ID3D11ShaderResourceView* m_shaderResourceView;
};

#endif