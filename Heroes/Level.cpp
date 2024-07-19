#include "Level.hpp"

namespace States
{
	Level::Level(StateMachine* pStateMachine) : State(pStateMachine, StateID::playing), movingEntitiesList(), staticEntitiesList()
		,collisionManager(&movingEntitiesList, &staticEntitiesList), pGraphicManager(Managers::GraphicManager::getInstance())
        ,skeleton(Math::CoordinateF(450, 600)), goblin(Math::CoordinateF(1400, 600)), mushroom(Math::CoordinateF(900, 600))
	{
        background.initialize(BACKGROUND_PATH, Math::CoordinateF(600, 400), Math::CoordinateF(WIDTH + 300, HEIGHT + 200));
        pPlayerControl = new Control::PlayerControl(&player);
       
        skeleton.setPlayer(&player);
        goblin.setPlayer(&player);
        mushroom.setPlayer(&player);

        movingEntitiesList.addEntity(&player);
        movingEntitiesList.addEntity(&skeleton);
        movingEntitiesList.addEntity(&goblin);
        movingEntitiesList.addEntity(&mushroom);

        Entities::Projectiles::Bomb* bomb = goblin.bomb;
        movingEntitiesList.addEntity(bomb);

        for (int i = 0; i < 20; i++)
        {
            Entities::Obstacles::Platform* platform = new Entities::Obstacles::Platform(Math::CoordinateF(-500 + 192 * i, 800));
            staticEntitiesList.addEntity(platform);
        } 
	}

    Level::~Level()
    {

    }

    void Level::update(const float dt)
    {
        pGraphicManager->centerView(Math::CoordinateF(player.getPosition().x, player.getPosition().y/2 + PLATFORM_HEIGHT));
        background.update(Math::CoordinateF(player.getPosition().x, 370));
            for (int i = 0; i < movingEntitiesList.getSize(); i++)
            {
                movingEntitiesList[i]->update(dt);
            }

            collisionManager.collide();
    }

    void Level::render()
    {
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