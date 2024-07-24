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
		int life = pPlayer->getLife();

		for (int i = 5; i >= 0; i--)
		{
			if (life >= 10000 * (i + 1))
			{
				hearts[i].update(full, Math::CoordinateF(position.x + HEART_SIZE_X * 1.4 * i, position.y));
			}
			else if (life >= 10000 * i + 5000)
			{
				hearts[i].update(half, Math::CoordinateF(position.x + HEART_SIZE_X * 1.4 * i, position.y));
			}
			else
			{
				hearts[i].update(empty, Math::CoordinateF(position.x + HEART_SIZE_X * 1.4 * i, position.y));
			}
			

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