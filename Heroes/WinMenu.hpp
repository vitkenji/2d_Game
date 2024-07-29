#pragma once
#include "Menu.hpp"
#include "State.hpp"
#include "Level.hpp"
#include "TextControl.hpp"

namespace Menus
{
	class WinMenu : public Menu, public States::State
	{
	private:
		GraphicalElements::Text title;
		GraphicalElements::Text points;
		GraphicalElements::Text name;
		GraphicalElements::Text nameLabel;
		Control::TextControl textControl;
		unsigned int pointsToIncrement;

		States::Level* pLevel;

	public:
		WinMenu(States::StateMachine* pStateMachine, States::Level* pLevel);
		~WinMenu();

		void update(const float dt);
		void render();
		void execute();
		void resetState();
		void saveInLeaderboard();

	};
}