#include "Game.hpp"

namespace States
{
	Game::Game() : clock(), dt(0), pGraphic(Managers::GraphicManager::getInstance()), pEvent(Managers::EventManager::getInstance())
	{
		clock.restart();
        
        State* states = new States::Level(this);
        insertState(states);

        states = static_cast<State*>(new Menus::PauseMenu(this, dynamic_cast<States::Level*>(statesMap[StateID::playing])));
        insertState(states);

        states = static_cast<State*>(new Menus::MainMenu(this));
        insertState(states);

        states = static_cast<State*>(new Menus::LeaderboardMenu(this));
        insertState(states);

        states = static_cast<State*>(new Menus::GameOverMenu(this, dynamic_cast<States::Level*>(statesMap[StateID::playing])));
        insertState(states);

        states = static_cast<State*>(new Menus::WinMenu(this, dynamic_cast<States::Level*>(statesMap[StateID::playing])));
        insertState(states);

        changeCurrentState(StateID::mainMenu);

		execute();

	}

	Game::~Game()
	{

	}

	void Game::execute()
	{

        while (pGraphic->isWindowOpen())
        {
            pGraphic->clear();
            pEvent->pollEvents();
           
            if (dt < TICK_RATE)
            {
                dt += clock.getElapsedTime().asSeconds();
                clock.restart();
            }
            else
            {
                updateCurrentState(0.01);
                dt -= TICK_RATE;
            }

            renderCurrentState();
            pGraphic->display();
            
        }
	}

    void Game::quit()
    {
        pGraphic->closeWindow();
    }
}