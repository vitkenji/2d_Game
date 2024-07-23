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

		for (int i = 0; i < 6; i++)
		{
			hearts[i].update(full, Math::CoordinateF(position.x + HEART_SIZE_X * 1.4 * i, position.y));

		}
		if (life < 60000)
		{
			if (life >= 55000)
			{
				hearts[5].update(half, Math::CoordinateF(position.x + HEART_SIZE_X * 1.4 * 5, position.y));
			}
			else if (life < 50000)
			{
				hearts[5].update(empty, Math::CoordinateF(position.x + HEART_SIZE_X * 1.4 * 5, position.y));
				if (life >= 45000)
				{
					hearts[4].update(half, Math::CoordinateF(position.x + HEART_SIZE_X * 1.4 * 4, position.y));
				}
				if (life < 40000)
				{
					hearts[4].update(empty, Math::CoordinateF(position.x + HEART_SIZE_X * 1.4 * 4, position.y));
					if (life >= 35000)
					{
						hearts[3].update(half, Math::CoordinateF(position.x + HEART_SIZE_X * 1.4 * 3, position.y));
					}
					if (life < 30000)
					{
						hearts[3].update(empty, Math::CoordinateF(position.x + HEART_SIZE_X * 1.4 * 3, position.y));
						if (life >= 25000)
						{
							hearts[2].update(half, Math::CoordinateF(position.x + HEART_SIZE_X * 1.4 * 2, position.y));
						}
						if (life < 20000)
						{
							hearts[2].update(empty, Math::CoordinateF(position.x + HEART_SIZE_X * 1.4 * 2, position.y));
							if (life >= 15000)
							{
								hearts[1].update(half, Math::CoordinateF(position.x + HEART_SIZE_X * 1.4 * 1, position.y));
							}
							if (life < 10000)
							{
								hearts[1].update(empty, Math::CoordinateF(position.x + HEART_SIZE_X * 1.4 * 1, position.y));
								if (life >= 5000)
								{
									hearts[0].update(half, Math::CoordinateF(position.x, position.y));
								}
								if (life < 0)
								{
									hearts[0].update(empty, Math::CoordinateF(position.x, position.y));
								}
							}
						}
					}
				}

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