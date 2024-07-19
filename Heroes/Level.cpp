#include "Level.hpp"

namespace States
{
	Level::Level(StateMachine* pStateMachine) : State(pStateMachine, StateID::playing), movingEntitiesList(), staticEntitiesList()
		,collisionManager(&movingEntitiesList, &staticEntitiesList)
        ,skeleton(Math::CoordinateF(450, 600)), goblin(Math::CoordinateF(900, 600))
	{
        background.initialize(BACKGROUND_PATH, Math::CoordinateF(600, 400), Math::CoordinateF(WIDTH + 30, HEIGHT + 20));
        pPlayerControl = new Control::PlayerControl(&player);
       
        skeleton.setPlayer(&player);
        goblin.setPlayer(&player);

        movingEntitiesList.addEntity(&player);
     //   movingEntitiesList.addEntity(&skeleton);
        movingEntitiesList.addEntity(&goblin);

        Entities::Projectiles::Bomb* bomb = goblin.bomb;
        movingEntitiesList.addEntity(bomb);

        for (int i = 0; i < 8; i++)
        {
            Entities::Obstacles::Platform* platform = new Entities::Obstacles::Platform(Math::CoordinateF(0 + 192 * i, 780));
            staticEntitiesList.addEntity(platform);
        } 
	}

    Level::~Level()
    {

    }

    void Level::update(const float dt)
    {
            for (int i = 0; i < movingEntitiesList.getSize(); i++)
            {
                movingEntitiesList[i]->update(dt);
            }

            collisionManager.collide();
    }

    void Level::render()
    {
        std::cout << movingEntitiesList.getSize() << std::endl;
        background.render();
        for (int i = 0; i < movingEntitiesList.getSize(); i++)
        {
            movingEntitiesList[i]->render();
        }

        for (int i = 0; i < staticEntitiesList.getSize(); i++)
        {

            staticEntitiesList[i]->render();
        }
    }

    void Level::resetState()
    {

    }
}