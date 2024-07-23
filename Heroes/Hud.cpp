#include "Hud.hpp"
#include "Player.hpp"

namespace GraphicalElements
{
	Hud::Hud(Entities::Characters::Player* pPlayer) : Ent(), pPlayer(pPlayer), pGraphicManager(Managers::GraphicManager::getInstance())
	{
		hearts = new Heart[6];
		initialize();
	}

	Hud::~Hud()
	{

	}

	void Hud::update(const float dt)
	{
		position = pGraphicManager->getHudPosition();
		updateHearts();
	}

	void Hud::updateHearts()
	{
		std::cout << "pPlayer X: " << pPlayer->getPosition().x - 590 + HEART_SIZE_X * 1.4  <<std::endl;
		std::cout << "pPlayer Y: " << pPlayer->getPosition().y - 700 << std::endl;
		std::cout << "position X: " << position.x << std::endl;
		std::cout << "position Y: " << position.y << std::endl;
		
		for (int i = 0; i < 6; i++)
		{
			hearts[i].update(full, Math::CoordinateF(position.x + HEART_SIZE_X * 1.4 * i, position.y));
		}
	}

	void Hud::render()
	{
		for (int i = 0; i < 6; i++)
		{
			hearts[i].render();
		}
	}

	void Hud::setPlayer(Entities::Characters::Player* pPlayer)
	{
		this->pPlayer = pPlayer;
	}

	void Hud::initialize()
	{

	}

}