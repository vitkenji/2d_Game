#pragma once
#include "Menu.hpp"
#include "State.hpp"
#include "std.h"
#include "Text.hpp"
#include "Button.hpp"

namespace Menus
{
	class LeaderboardMenu : public Menu, public States::State
	{
	private:
		std::vector<GraphicalElements::Text*> ranking;
		std::vector<GraphicalElements::Text*>::iterator it;

	public:
		LeaderboardMenu(States::StateMachine* pStateMachine);
		~LeaderboardMenu();
		void update(const float dt);
		void render();
		void resetState();
		void execute();
		void buildLeaderboard();

	};
}