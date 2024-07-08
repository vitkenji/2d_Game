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
        Entities::Characters::Player player;

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
            player.sprite.update(GraphicalElements::fall, true, Math::CoordinateF(50, 50), dt);
            player.sprite.render();
            pGraphic->display();
            pGraphic->clear();
        }
	}
}