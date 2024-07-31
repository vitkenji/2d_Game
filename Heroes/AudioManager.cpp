#include "AudioManager.hpp"

namespace Managers
{
	AudioManager* AudioManager::instance = nullptr;

	AudioManager* AudioManager::getInstance()
	{
		if (instance == nullptr)
		{
			instance = new AudioManager();
		}
		return instance;
	}

	AudioManager::AudioManager() : audioMap(), bufferMap()
	{

	}

	AudioManager::~AudioManager()
	{
		std::map<const char*, sf::Sound*>::iterator i;
		for (i = audioMap.begin(); i != audioMap.end(); i++)
		{
			delete(i->second);
		}
	}

	sf::Sound* AudioManager::loadSound(const char* path, sf::SoundBuffer* buffer, sf::Sound* sound)
	{		
		if (!buffer->loadFromFile(path))
		{
			std::cout << "error loading sound" << std::endl;
			exit(1);
		}
		sound->setBuffer(*buffer);
		
	}

	sf::Music* AudioManager::loadMusic(const char* path, sf::Music* music)
	{
		if (!music->openFromFile(path))
		{
			std::cout << "error loading music" << std::endl;
			exit(1);
		}
	}



}