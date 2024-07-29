#pragma once
#include "std.h"

namespace Managers
{
	class AudioManager
	{
	private:
		sf::Music music;

	public:
		~AudioManager();
		void playAudio();
		void stopAudio();

	};
}