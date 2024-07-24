#include "Level.hpp"

namespace States
{
	Level::Level(StateMachine* pStateMachine) : State(pStateMachine, StateID::playing), movingEntitiesList(), staticEntitiesList()
		,collisionManager(&movingEntitiesList, &staticEntitiesList), pGraphicManager(Managers::GraphicManager::getInstance())
        ,skeleton(Math::CoordinateF(450, 600)), goblin(Math::CoordinateF(1800, 600)), mushroom(Math::CoordinateF(900, 600)),
        flyingEye(Math::CoordinateF(1400, 600)),
        fire(Math::CoordinateF(300, 700)),
        box(Math::CoordinateF(200, 500)),
        hud(&player)
	{
        background.initialize(BACKGROUND_PATH, Math::CoordinateF(600, 400), Math::CoordinateF(WIDTH + 300, HEIGHT + 200));
        pPlayerControl = new Control::PlayerControl(&player);
       
        skeleton.setPlayer(&player);
        goblin.setPlayer(&player);
        mushroom.setPlayer(&player);
        flyingEye.setPlayer(&player);

        movingEntitiesList.addEntity(&player);
        movingEntitiesList.addEntity(&skeleton);
        movingEntitiesList.addEntity(&goblin);
        movingEntitiesList.addEntity(&mushroom);
        movingEntitiesList.addEntity(&flyingEye);
        movingEntitiesList.addEntity(&fire); 
        movingEntitiesList.addEntity(&box);

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
            hud.update(dt);
            if (player.getLife() <= 0)
            {
                endLevel();
                changeState(gameOver);
            }

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
        hud.render();
    }

    void Level::resetState()
    {

    }

    void Level::endLevel()
    {
       
    }

}