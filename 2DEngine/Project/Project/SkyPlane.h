#include <d3d11.h>
#include <d3dx10math.h>


#include "TextureManager.h"

class SkyPlane
{
private:
	struct SkyPlaneType
	{
		float x, y, z;
		float tu, tv;
	};


	struct VertexType
	{
		D3DXVECTOR3 position;
		D3DXVECTOR2 texture;
	};

public:
	SkyPlane();
	SkyPlane(const SkyPlane&);
	~SkyPlane();

	bool Initilize(ID3D11Device*, WCHAR*, WCHAR*);
	void Shutdown();
	void Render(ID3D11DeviceContext*);
	void Frame();

	int GetIndexCount();
	ID3D11ShaderResourceView* GetCloudTexture1();
	ID3D11ShaderResourceView* GetCloudTexture2();

	float GetBrightness();
	float GetTranslation(int);

private:
	bool InitilizeSkyPlane(int, float, float, float, int);
	void ShutDownSkyPlane();

	bool InitilizeBuffers(ID3D11Device*, int);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);

	bool LoadTextures(ID3D11Device*, WCHAR*, WCHAR*);
	void ReleaseTextures();

private:
	SkyPlaneType* m_skyPlane;
	int m_vertexCount, m_indexCount;
	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	TextureManager *m_CloudTexture1, *m_CloudTexture2;
	float m_Brightness;

	float m_translationSpeed[4];
	float m_textureTranslation[4];



};