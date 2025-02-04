#pragma once
#include "std.h"
#include "Button.hpp"
#include "MenuControl.hpp"
#include "SingleFrameAnimation.hpp"
#include "GraphicManager.hpp"
#include "AudioManager.hpp"

namespace Menus
{
	class Menu
	{
	protected:
		std::vector<GraphicalElements::Button*> buttons;
		std::vector<GraphicalElements::Button*>::iterator i;
		int selected;
		int min;
		int max;
		Control::MenuControl menuControl;
		bool active;
		GraphicalElements::SingleFrameAnimation back;
		Managers::GraphicManager* pGraphicManager;
		Managers::AudioManager* pAudioManager;
		sf::Sound buttonSound;
		sf::SoundBuffer buttonBuffer;

		sf::Music music;

	public:
		Menu();
		virtual ~Menu();
		virtual void execute() = 0;
		void updateView();
		void selectDown();
		void selectUp();

	};
}