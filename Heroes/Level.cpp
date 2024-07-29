#include "Level.hpp"

namespace States
{
    Level::Level(StateMachine* pStateMachine) : State(pStateMachine, StateID::playing), movingEntitiesList(), staticEntitiesList(),player()
        , collisionManager(&movingEntitiesList, &staticEntitiesList), pGraphicManager(Managers::GraphicManager::getInstance()), hud(player), resume(false)
    {
        background.initialize(BACKGROUND_PATH, Math::CoordinateF(600, 400), Math::CoordinateF(WIDTH + 300, HEIGHT + 200));
        restartLevel();

        for (int i = 0; i < 20; i++)
        {
            Entities::Obstacles::Platform* platform = new Entities::Obstacles::Platform(Math::CoordinateF(-500 + 192 * i, 800));
            staticEntitiesList.addEntity(platform);
        }
        mud = new Entities::Obstacles::Mud(Math::CoordinateF(900, 800));
        water = new Entities::Obstacles::Water(Math::CoordinateF(600, 800));
        staticEntitiesList.addEntity(water);
        staticEntitiesList.addEntity(mud);

	}

    Level::~Level()
    {

    }

    void Level::update(const float dt)
    {
       
        pGraphicManager->centerView(Math::CoordinateF(player->getPosition().x, player->getPosition().y/2 + PLATFORM_HEIGHT));
        background.update(Math::CoordinateF(player->getPosition().x, 370));
       
            for (int i = 0; i < movingEntitiesList.getSize(); i++)
            {
                if (movingEntitiesList[i] == nullptr)
                {
                    std::cout << "error: ptr is nullptr: " << movingEntitiesList[i] << std::endl;
                }
                movingEntitiesList[i]->update(dt);
            }

            collisionManager.collide();
            hud.update(dt);
            if (player->getLife() <= 0)
            {
                changeState(gameOver);
            }
            else if (player->getPosition().x >= 2000)
            {
                changeState(win);
            }

    }

    void Level::render()
    {
        background.render();
        for (int i = 0; i < movingEntitiesList.getSize(); i++)
        {
            if (movingEntitiesList[i] == nullptr)
            {
                std::cout << "error: ptr is nullptr: " << movingEntitiesList[i] << std::endl;
            }
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
        std::cout << resume << std::endl;
        if (player->getPosition().x != 50.f && !resume)
        {
            resume = false;
            restartLevel();
        }
    }

    void Level::restartLevel()
    {

        movingEntitiesList.clearList();

        player = new Entities::Characters::Player();
        hud = GraphicalElements::Hud(player);
        skeleton = new Entities::Characters::Enemies::Skeleton(Math::CoordinateF(450, 600));
        goblin = new Entities::Characters::Enemies::Goblin(Math::CoordinateF(1800, 600));
        flyingEye = new Entities::Characters::Enemies::FlyingEye(Math::CoordinateF(1400, 600));
        mushroom = new Entities::Characters::Enemies::Mushroom(Math::CoordinateF(900, 600));
        box = new Entities::Obstacles::Box(Math::CoordinateF(200, 500));
        fire = new Entities::Obstacles::Fire(Math::CoordinateF(300, 700));

        Entities::Projectiles::Bomb* bomb = goblin->bomb;

        skeleton->setPlayer(player);
        goblin->setPlayer(player);
        mushroom->setPlayer(player);
        flyingEye->setPlayer(player);

        pPlayerControl = new Control::PlayerControl(player);

        skeleton->setPosition(Math::CoordinateF(450, 600));
        goblin->setPosition(Math::CoordinateF(1800, 600));
        box->setPosition(Math::CoordinateF(200, 500));
        fire->setPosition(Math::CoordinateF(300, 700));
        player->setPosition(Math::CoordinateF(50, 600));
        mushroom->setPosition(Math::CoordinateF(900, 600));
        flyingEye->setPosition(Math::CoordinateF(1400, 600));

        movingEntitiesList.addEntity(player);
        movingEntitiesList.addEntity(skeleton);
        movingEntitiesList.addEntity(goblin);
        movingEntitiesList.addEntity(mushroom);
        movingEntitiesList.addEntity(flyingEye);
        movingEntitiesList.addEntity(fire);
        //movingEntitiesList.addEntity(box);
        movingEntitiesList.addEntity(bomb);

    }

    void Level::setResume(bool resume)
    {
        std::cout << "before: " << this->resume << std::endl;
        this->resume = resume;
        std::cout << "after: " << this->resume << std::endl;
    }

    int Level::getPlayerPoints()
    {
        return player->getPoints();
    }


}