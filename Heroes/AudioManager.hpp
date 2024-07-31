#pragma once
#include "std.h"

namespace Managers
{
	class AudioManager
	{
	private:
		sf::Music backgroundMusic;
		std::map<const char*, sf::Sound*> audioMap;
		std::map<const char*, sf::SoundBuffer*> bufferMap;
		static AudioManager* instance;
		AudioManager();

	public:
		static AudioManager* getInstance();
		~AudioManager();
		
		sf::Music* loadMusic(const char* path, sf::Music* music);
		sf::Sound* loadSound(const char* path, sf::SoundBuffer* buffer, sf::Sound* sound);
		void playAudio(sf::Sound sound);
		void stopAudio(sf::Sound sound);
		void setVolume(float volume);

	};
}