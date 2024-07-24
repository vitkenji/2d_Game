#pragma once
#include "std.h"
#include "GraphicManager.hpp"
#include "EventManager.hpp"
#include "StateMachine.hpp"
#include "MainMenu.hpp"
#include "Level.hpp"
#include "PauseMenu.hpp"
#include "GameOverMenu.hpp"
#include "LeaderboardMenu.hpp"

namespace States
{
	class Game : public StateMachine
	{
	private:
		sf::Clock clock;
		float dt;
		Managers::GraphicManager* pGraphic;
		Managers::EventManager* pEvent;
		
	public:
		Game();
		~Game();
		void execute();
		void quit();
	};
}