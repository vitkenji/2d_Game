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
		updateHearts();
	}

	void Hud::updateHearts()
	{
		
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