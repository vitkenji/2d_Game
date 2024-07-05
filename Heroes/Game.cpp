#include "Game.hpp"

namespace States
{
	Game::Game() : clock(), dt(0), pGraphic(Managers::GraphicManager::getInstance())
	{
		clock.restart();
		execute();
	}

	Game::~Game()
	{

	}

	void Game::execute()
	{
        GraphicalElements::MultiFrameAnimation body;
        body.addNewAnimation(GraphicalElements::idle, PLAYER_IDLE_PATH, 8, 0.8);

        while (pGraphic->isWindowOpen())
        {
            sf::Event event;
            while (pGraphic->getWindow()->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    pGraphic->closeWindow();
            }

            if (dt < TICK_RATE) {
                dt += clock.getElapsedTime().asSeconds();
                clock.restart();
            }
            else {
                dt -= TICK_RATE;
            }
            body.update(GraphicalElements::idle, false, Math::CoordinateF(50, 50), dt);
            body.render();
            pGraphic->display();
            pGraphic->clear();
        }
	}
}