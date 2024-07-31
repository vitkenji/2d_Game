#pragma once
#include "Menu.hpp"
#include "State.hpp"

namespace States {
	class Game;
}

namespace Menus
{
	class MainMenu : public Menu, public States::State
	{
	private:
		States::Game* pGame;
		GraphicalElements::Text title;
		sf::Music music;

	public:
		MainMenu(States::Game* pGame);
		~MainMenu();
		void update(const float dt);
		void render();
		void resetState();
		void execute();

	};

}