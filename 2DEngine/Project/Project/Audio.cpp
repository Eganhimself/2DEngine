#include "Audio.h"




CAudioManager *CAudioManager::pInstance = 0;

CAudioManager *CAudioManager::Instance()
{

	
	if(CAudioManager::pInstance == 0)
	{
			CAudioManager::pInstance = new CAudioManager;
	}

return CAudioManager::pInstance;


}




//initialize sound system
CAudioManager::CAudioManager()
{
			//allocate memory for the FMOD system object
		result = FMOD::System_Create(&m_pSystem);

		m_volumeSet = 1.0;
		//initialize the FMOD system object
		m_pSystem->init(32, FMOD_INIT_NORMAL, 0);

		result = m_pSystem->createStream("../Sounds/R.mp3", FMOD_SOFTWARE | FMOD_LOOP_NORMAL | FMOD_3D, 0, &m_pSound[0]);
		result = m_pSystem->createStream("../Sounds/The.mp3", FMOD_SOFTWARE | FMOD_LOOP_NORMAL | FMOD_3D, 0, &m_pSound[1]);

	



	pauseSound = false;





	m_frequency = 0; 
	m_volume = 0;
	pan = 0;
    playing = false;




   






	











 	

}

CAudioManager::~CAudioManager()
{
		FMOD_RESULT result;
// release resources
result = m_pSound[0]->release();
result = m_pSound[1]->release();


result = m_pSystem->close();


result = m_pSystem->release();

}



 void CAudioManager::Play(int ID)
{





if(pauseSound == false)
{

	
	m_pSystem->playSound(FMOD_CHANNEL_FREE, m_pSound[ID], false, &m_pChannel);
	
}





}


void CAudioManager::StopSound(int ID)
{
m_pChannel->stop();
}


void CAudioManager::PauseSound(int ID)
{
m_pChannel->setPaused(true);
}


void CAudioManager::UnpauseSound(int ID)
{
m_pChannel->setPaused(false);
}
















void CAudioManager::Volume(float Volume)
{
	m_volumeSet = Volume;

	m_pChannel->setVolume(m_volumeSet + 0.1f);


}





void CAudioManager::Update()
{




	m_pChannel->getVolume(&m_volumeSet);






	m_pChannel->getPan(&AudioPaning);
					








 



m_pSystem->update();


}

