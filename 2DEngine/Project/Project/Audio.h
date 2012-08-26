/*

Audio class for playing soundtracks in the game engine



*/












#ifndef CAUDIOMANAGER_H
#define CAUDIOMANAGER_H


#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string>
#include <cstring>
#include <vector>
#include <fmod.h>


#include <fmod.hpp>
#include "fmod_errors.h"

using namespace std;

#define SONG = 1;

struct SOUND_FILE_DATA{
int soundID;
std::string filename;
std::string description;
};





class CAudioManager 
{
public:
	CAudioManager();
	~CAudioManager();
	static CAudioManager *Instance();
	virtual void Play(int ID);
	virtual void StopSound(int ID);
	virtual void PauseSound(int ID);
	virtual void Volume(float Volume);
	virtual void UnpauseSound(int ID);
	void Update();


	
private:



static CAudioManager *pInstance;


FMOD::System* m_pSystem;
FMOD::Sound* m_pSound[2];
FMOD::Channel* m_pChannel;


FMOD::Reverb *m_pReverb;


FMOD_RESULT result;



float m_frequency, m_volume, pan;
bool playing;










bool pauseSound;

float m_volumeSet;




float AudioPaning;









};


#endif