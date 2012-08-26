#include <d3d11.h>
#include <d3dx10math.h>
#include <d3dx11async.h>
#include <fstream>
using namespace std;

class SkyPlaneShader
{
private:
	struct MatrixBufferType
	{
		D3DXMATRIX world;
		D3DXMATRIX view;
		D3DXMATRIX projection;
	};

	struct SkyBufferType
	{
		float firstTranslationX;
		float firstTranslationZ;
		float secondTranslationX;
		float secondTranslationZ;
		float brightness;
		D3DXVECTOR3 padding;
	};

public:
	SkyPlaneShader();
	SkyPlaneShader(const SkyPlaneShader&);
	~SkyPlaneShader();

	bool Intilize(ID3D11Device*, HWND);
	void ShutDown();
	bool Render(ID3D11DeviceContext*, int, D3DXMATRIX, D3DXMATRIX, D3DXMATRIX, ID3D11ShaderResourceView*, ID3D11ShaderResourceView*, float, float, float, 
		    float, float);

private:
	bool InitilizeShader(ID3D11Device*, HWND, WCHAR*, WCHAR*);
	void ShutDownShader();
	void OutputErrorMessage(ID3D10Blob*, HWND, WCHAR*);

	bool SetShaderParameters(ID3D11DeviceContext*, D3DXMATRIX, D3DXMATRIX, D3DXMATRIX, ID3D11ShaderResourceView*, ID3D11ShaderResourceView*, float, float, 
				 float, float, float);
	void RenderShader(ID3D11DeviceContext*, int);

private:
	ID3D11VertexShader* m_vertexShader;
	ID3D11PixelShader* m_pixelShader;
	ID3D11InputLayout* m_layout;
	ID3D11SamplerState* m_sampleState;
	ID3D11Buffer* m_matrixBuffer;


	ID3D11Buffer* m_skyBuffer;



















};