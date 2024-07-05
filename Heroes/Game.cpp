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
        Entities::MovingEntity player = Entities::MovingEntity(Math::CoordinateF(50, 50), Math::CoordinateF(100, 100), Entities::player);

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
            player.sprite.update(GraphicalElements::idle, false, Math::CoordinateF(50, 50), dt);
            player.sprite.render();
            pGraphic->display();
            pGraphic->clear();
        }
	}
}