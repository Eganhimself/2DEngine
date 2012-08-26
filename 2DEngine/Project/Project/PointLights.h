#ifndef _LightManager_H_
#define _LightManager_H_


//////////////
// INCLUDES //
//////////////
#include <d3dx10math.h>


////////////////////////////////////////////////////////////////////////////////
// Class name: LightManager
////////////////////////////////////////////////////////////////////////////////
class LightManager
{
public:
	LightManager();
	LightManager(const LightManager&);
	~LightManager();

	void SetDiffuseColor(float, float, float, float);
	void SetPosition(float, float, float);

	D3DXVECTOR4 GetDiffuseColor();
	D3DXVECTOR4 GetPosition();

private:
	D3DXVECTOR4 m_diffuseColor;
	D3DXVECTOR4 m_position;
};

#endif