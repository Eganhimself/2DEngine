////////////////////////////////////////////////////////////////////////////////
// Filename: applicationclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _APPLICATIONCLASS_H_
#define _APPLICATIONCLASS_H_


/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "inputclass.h"
#include "D3DManager.h"
#include "cameraclass.h"
#include "terrainclass.h"
#include "timerclass.h"
#include "positionclass.h"
#include "fpsclass.h"
#include "cpuclass.h"
#include "fontshaderclass.h"
#include "textclass.h"
#include "terrainshaderclass.h"
#include "lightclass.h"
#include "ModelLoader.h"
#include "textureshaderclass.h"
#include "lightshaderclass.h"
#include "PointLights.h"
#include "ShaderManager.h"
#include "SkyDome.h"
#include "SkyDomeShader.h"
#include "SkyPlane.h"
#include "SkyPlaneshader.h"
#include "Map.h"


////////////////////////////////////////////////////////////////////////////////
// Class name: ApplicationClass
////////////////////////////////////////////////////////////////////////////////
class ApplicationClass
{
public:
	ApplicationClass();
	ApplicationClass(const ApplicationClass&);
	~ApplicationClass();

	bool Initialize(HINSTANCE, HWND, int, int);
	void Shutdown();
	bool Frame();

private:
	bool HandleInput(float);
	bool RenderGraphics();

private:
	InputClass* m_Input;
	D3DManager* m_Direct3D;
	CameraClass* m_Camera;
	TerrainClass* m_Terrain;
	TimerClass* m_Timer;
	PositionClass* m_Position;
	FpsClass* m_Fps;
	CpuClass* m_Cpu;
	FontShaderClass* m_FontShader;
	TextClass* m_Text;

	LightClass* m_Light;
	ModelLoader* m_Model;
	TextureShaderClass* m_TextureShader;
	LightShaderClass* m_LightShader;
	LightManager *m_Light1, *m_Light2, *m_Light3, *m_Light4;
	ShaderManager* m_ShaderManager;
	SkyDome* m_SkyDome;
	SkyDomeShader* m_SkyDomeShader;
	SkyPlane *m_SkyPlane;
	SkyPlaneShader* m_SkyPlaneShader;
	Map* m_MiniMap;
};




#endif