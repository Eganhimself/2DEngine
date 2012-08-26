/*


Audio system for playing sound events from the FMOD designer



*/












#include "fmod_event.hpp"
#include "fmod.hpp"
#include "fmod_errors.h"
#include "fmod.h"



class CAudioEvents 
{
public:
	CAudioEvents();
	~CAudioEvents();
	static CAudioEvents *Instance();
	virtual void Play(int ID);
	virtual void StopSound(int ID);
	virtual void PauseSound(int ID);
	virtual void Volume(float Volume);
	virtual void UnpauseSound(int ID);
	void Update();

private:

	static CAudioEvents *pInstance;

	FMOD::System *m_pSystem;
	FMOD::EventSystem *m_pEventsystem;
	FMOD::EventGroup *m_pEventgroup;
	FMOD::EventCategory *m_pMastercategory;
	FMOD::Event			*m_pAudioSample[2];





















};