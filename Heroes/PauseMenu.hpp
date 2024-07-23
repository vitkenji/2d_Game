#pragma once
#include "Menu.hpp"
#include "State.hpp"
#include "Level.hpp"
#include "StateMachine.hpp"

namespace Menus
{
	class PauseMenu : public Menu, public States::State
	{
	private:
		States::Level* pLevel;
		GraphicalElements::Text title;

	public:
		PauseMenu(States::StateMachine* pStateMachine, States::Level* pLevel);
		~PauseMenu();
		void update(const float dt);
		void render();
		void execute();
		void resetState();
		void triggerPauseMenu();
	};

}