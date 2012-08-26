#include "ShaderManager.h"

ShaderManager::ShaderManager()
{


}


ShaderManager::ShaderManager(const ShaderManager& other)
{
}


ShaderManager::~ShaderManager()
{
}


bool ShaderManager::Initialize(ID3D11Device* device, HWND hwnd)
{
	bool result;

	m_TerrainRender = new TerrainShaderClass;
	if(!m_TerrainRender)
	{
		return false;
	}


	result = m_TerrainRender->Initialize(device, hwnd);
		if(!result)
	{
		MessageBox(hwnd, L"Could not initialize the terrain shader object.", L"Error", MB_OK);
		return false;
	}

		m_LightingRender = new LightShaderClass;
		if(!m_LightingRender)
		{
			return false;
		}

		result =  m_LightingRender->Initialize(device, hwnd);
		if(!result)
		{
			MessageBox(hwnd, L"Could not initialize lighting shader object.", L"Error", MB_OK);
		}


		m_ReflectionRender = new ReflectionShaderClass;
		if(!m_ReflectionRender)
		{
			 return false;

		}

		result = m_ReflectionRender->Initialize(device, hwnd);
		if(!result)
		{

			MessageBox(hwnd, L"Could not initilize reflection shader object", L"Error", MB_OK);

		}

}


void ShaderManager::Shutdown()
{


	return;
}

bool ShaderManager::TerrainRender(ID3D11DeviceContext* deviceContext, int indexCount, D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix, 
								D3DXMATRIX projectionMatrix, D3DXVECTOR4 ambientColor, D3DXVECTOR4 diffuseColor, D3DXVECTOR3 lightDirection, 
								ID3D11ShaderResourceView* texture)
{
	bool result;

	result = m_TerrainRender->Render(deviceContext, indexCount, worldMatrix, viewMatrix, projectionMatrix, ambientColor, diffuseColor, lightDirection, texture);
	if(!result)
	{
		return false;
	}

	return true;


}

bool ShaderManager::LightRender(ID3D11DeviceContext* deviceContext, int indexCount, D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix, 
							  D3DXMATRIX projectionMatrix, ID3D11ShaderResourceView* texture, D3DXVECTOR4 diffuseColor[],
							  D3DXVECTOR4 lightPosition[])
{
	bool result;

	result = m_LightingRender->Render(deviceContext, indexCount, worldMatrix, viewMatrix, projectionMatrix, texture, diffuseColor, lightPosition);
	if(!result)
	{
		return false;

	}

	return true;






}