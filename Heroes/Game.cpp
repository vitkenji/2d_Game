#include "Game.hpp"

namespace States
{
	Game::Game() : clock(), dt(0), pGraphic(Managers::GraphicManager::getInstance())
	{
        background.initialize(BACKGROUND_PATH, Math::CoordinateF(850, 500), Math::CoordinateF(WIDTH + 30, HEIGHT + 20));
        pPlayerControl = new Control::PlayerControl(&player);
		clock.restart();
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
            background.render();

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
            player.sprite.update(GraphicalElements::idle, true, Math::CoordinateF(50, 50), dt);
            player.sprite.render();
            pGraphic->display();
            
        }
	}
}