#include "Hud.hpp"
#include "Player.hpp"

namespace GraphicalElements
{
	Hud::Hud(Entities::Characters::Player* pPlayer) : Ent(), pPlayer(pPlayer), pGraphicManager(Managers::GraphicManager::getInstance()), 
		points(pGraphicManager->getHudPosition(), "00000", FONT1_PATH)
	{
		
		points.setFontSize(18);

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
		updatePoints();
	}

	void Hud::updatePoints()
	{
		std::string updatedPoints = std::to_string(pPlayer->getPoints());

		while (updatedPoints.length() < 5)
		{
			updatedPoints.insert(0, "0");
		}
		points.setTextInfo(updatedPoints);
		points.setPosition(Math::CoordinateF(position.x + 60, position.y + 55));
		
	}

	void Hud::updateHearts()
	{
		for (int i = 5; i >= 0; i--)
		{
			if (pPlayer->getLife() >= 10000 * (i + 1))
			{
				hearts[i].update(full, Math::CoordinateF(position.x + HEART_SIZE_X * 1.2 * i, position.y));
			}
			else if (pPlayer->getLife() >= 10000 * i + 5000)
			{
				hearts[i].update(half, Math::CoordinateF(position.x + HEART_SIZE_X * 1.2 * i, position.y));
			}
			else
			{
				hearts[i].update(empty, Math::CoordinateF(position.x + HEART_SIZE_X * 1.2 * i, position.y));
			}
		}		
	}

	void Hud::render()
	{
		for (int i = 0; i < 6; i++)
		{
			hearts[i].render();
		}
		points.render();
	}

	void Hud::setPlayer(Entities::Characters::Player* pPlayer)
	{
		this->pPlayer = pPlayer;
	}

	void Hud::initialize()
	{

	}

}