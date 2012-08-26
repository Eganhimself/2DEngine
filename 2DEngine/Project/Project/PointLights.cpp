#include "PointLights.h"




LightManager::LightManager()
{
}


LightManager::LightManager(const LightManager& other)
{
}


LightManager::~LightManager()
{
}


void LightManager::SetDiffuseColor(float red, float green, float blue, float alpha)
{
	m_diffuseColor = D3DXVECTOR4(red, green, blue, alpha);
	return;
}


void LightManager::SetPosition(float x, float y, float z)
{
	m_position = D3DXVECTOR4(x, y, z, 1.0f);
	return;
}


D3DXVECTOR4 LightManager::GetDiffuseColor()
{
	return m_diffuseColor;
}


D3DXVECTOR4 LightManager::GetPosition()
{
	return m_position;
}