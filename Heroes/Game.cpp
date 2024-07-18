#include "Game.hpp"

namespace States
{
	Game::Game() : clock(), dt(0), pGraphic(Managers::GraphicManager::getInstance()), pEvent(Managers::EventManager::getInstance()), 
        skeleton(Math::CoordinateF(450,50)), goblin(Math::CoordinateF(900, 200)), collisionManager(&movingEntitiesList, &staticEntitiesList)
	{
        background.initialize(BACKGROUND_PATH, Math::CoordinateF(600, 400), Math::CoordinateF(WIDTH + 30, HEIGHT + 20));
        pPlayerControl = new Control::PlayerControl(&player);
		clock.restart();

        skeleton.setPlayer(&player);
        goblin.setPlayer(&player);

        movingEntitiesList.addEntity(&player);
        movingEntitiesList.addEntity(&skeleton);
        movingEntitiesList.addEntity(&goblin);

        std::list<Entities::Projectiles::Bomb*>::iterator i;
        for (i = goblin.bombList.begin(); i != goblin.bombList.end(); i++)
        {
            movingEntitiesList.addEntity((*i));
        }
       
        for (int i = 0; i < 8; i++)
        {
            Entities::Obstacles::Platform* platform = new Entities::Obstacles::Platform(Math::CoordinateF(0 + 192 * i, 780));
            staticEntitiesList.addEntity(platform);
        }
        
        State* states;
        states = static_cast<State*>(new Menus::MainMenu(this));
        insertState(states);

        states = new Level(this);
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
            pEvent->pollEvents();
            pGraphic->clear();
            //background.render();
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
            /*
            for (int i = 0; i < movingEntitiesList.getSize(); i++)
            {
                movingEntitiesList[i]->update(dt);
                movingEntitiesList[i]->render();
            }
            
            for (int i = 0; i < staticEntitiesList.getSize(); i++)
            {
            
                staticEntitiesList[i]->render();
            }*/

            //collisionManager.collide();

            renderCurrentState();
            pGraphic->display();
            
        }
	}
}