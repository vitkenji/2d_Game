#pragma once
#include "Menu.hpp"
#include "State.hpp"
#include "Level.hpp"
#include "StateMachine.hpp"

namespace Menus
{
	class GameOverMenu : public Menu, public States::State
	{
	private:
		States::Level* pLevel;
		GraphicalElements::Text title;

	public:
		GameOverMenu(States::StateMachine* pStateMachine, States::Level* pLevel);
		~GameOverMenu();
		void update(const float dt);
		void render();
		void execute();
		void resetState();
	};
}