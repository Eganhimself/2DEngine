#include "AudioEvent.h"




CAudioEvents *CAudioEvents::pInstance = 0;

CAudioEvents *CAudioEvents::Instance()
{

	
	if(CAudioEvents::pInstance == 0)
	{
			CAudioEvents::pInstance = new CAudioEvents;
	}

return CAudioEvents::pInstance;


}

CAudioEvents::CAudioEvents()
{




	

	FMOD::EventSystem_Create(&m_pEventsystem);
	m_pEventsystem->init(32, FMOD_3D, 0, FMOD_EVENT_INIT_NORMAL);

	m_pEventsystem->setMediaPath((char *) "C:/Users/Egan/Desktop/Backup/Masters/CGP2/Engine/DGESample_V1/Audio/");
	m_pEventsystem->load("GameEvents.fev", 0, 0);


	
	m_pEventsystem->getGroup("GameEvents/TankWar", FMOD_EVENT_DEFAULT, &m_pEventgroup);
	
	

	
	m_pEventgroup->getEvent("PlayerFiring", FMOD_3D, &m_pAudioSample[0]);
	m_pEventgroup->getEvent("AITankFiring", FMOD_3D, &m_pAudioSample[1]);


	m_pEventsystem->getCategory("master", &m_pMastercategory);



}

void CAudioEvents::Play(int ID)
{



m_pAudioSample[ID]->start();




}

void CAudioEvents::StopSound(int ID)
{


	m_pAudioSample[ID]->stop();





}

void CAudioEvents::Volume(float volume)
{









}

void CAudioEvents::Update()
{


		m_pEventsystem->update();







}

void CAudioEvents::UnpauseSound(int ID)
{







}


void CAudioEvents::PauseSound(int ID)
{








}