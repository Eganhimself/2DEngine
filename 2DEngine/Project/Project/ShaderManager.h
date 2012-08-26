#include "D3DManager.h"
#include "terrainshaderclass.h"
#include "lightshaderclass.h"
#include "Reflectionshaderclass.h"
#include "Refractionshader.h"
#include "WaterShader.h"



class ShaderManager
{

public:
	ShaderManager();
	ShaderManager(const ShaderManager&);
	~ShaderManager();

	bool Initialize(ID3D11Device*, HWND);
	void Shutdown();

	bool TerrainRender(ID3D11DeviceContext* deviceContext, int indexCount, D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix, 
								D3DXMATRIX projectionMatrix, D3DXVECTOR4 ambientColor, D3DXVECTOR4 diffuseColor, D3DXVECTOR3 lightDirection, 
								ID3D11ShaderResourceView* texture);
	bool LightRender(ID3D11DeviceContext* deviceContext, int indexCount, D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix, 
							  D3DXMATRIX projectionMatrix, ID3D11ShaderResourceView* texture, D3DXVECTOR4 diffuseColor[],
							  D3DXVECTOR4 lightPosition[]);
	bool ReflectionRender(ID3D11DeviceContext* deviceContext, int indexCount, D3DXMATRIX worldMatrix, 
				   D3DXMATRIX viewMatrix, D3DXMATRIX projectionMatrix, ID3D11ShaderResourceView* texture,
				   ID3D11ShaderResourceView* reflectionTexture, D3DXMATRIX reflectionMatrix);

	bool WaterRender(ID3D11DeviceContext* deviceContext, int indexCount, D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix, 
			      D3DXMATRIX projectionMatrix, D3DXMATRIX reflectionMatrix, 
			      ID3D11ShaderResourceView* reflectionTexture, ID3D11ShaderResourceView* refractionTexture,
			      ID3D11ShaderResourceView* normalTexture, float waterTranslation, float reflectRefractScale);

	bool RefractionRender(ID3D11DeviceContext* deviceContext, int indexCount, D3DXMATRIX worldMatrix, 
				   D3DXMATRIX viewMatrix, D3DXMATRIX projectionMatrix, ID3D11ShaderResourceView* texture, 
				   D3DXVECTOR3 lightDirection, D3DXVECTOR4 ambientColor, D3DXVECTOR4 diffuseColor, 
				   D3DXVECTOR4 clipPlane);

	//bool SkyDomeRender(ID3D11DeviceContext*, int, D3DXMATRIX, D3DXMATRIX, D3DXMATRIX, D3DXVECTOR4, D3DXVECTOR4);



private:
	TerrainShaderClass* m_TerrainRender;
	LightShaderClass* m_LightingRender;
	ReflectionShaderClass* m_ReflectionRender;
	RefractionShaderClass* m_RefractionShader;
	WaterShaderClass* m_WaterShader;












};