#ifndef _Map_H_
#define _Map_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "HUDElement.h"
#include "textureshaderclass.h"


////////////////////////////////////////////////////////////////////////////////
// Class name: Map
////////////////////////////////////////////////////////////////////////////////
class Map
{
public:
	Map();
	Map(const Map&);
	~Map();

	bool Initialize(ID3D11Device*, HWND, int, int, D3DXMATRIX);
	void Shutdown();
	bool Render(ID3D11DeviceContext*, D3DXMATRIX, D3DXMATRIX, TextureShaderClass*);
	
	void PositionUpdate(float, float);

private:
	int m_mapLocationX, m_mapLocationY, m_pointLocationX, m_pointLocationY;
	float m_mapSizeX, m_mapSizeY, m_terrainWidth, m_terrainHeight;
	D3DXMATRIX m_viewMatrix;
	HUDElement *m_MiniMapBitmap, *m_Border, *m_Point;
};

#endif