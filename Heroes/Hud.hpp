#pragma once
#include "Ent.hpp"
#include "Heart.hpp"
#include "GraphicManager.hpp"
#include "Text.hpp"
#include "std.h"

namespace Entities
{
	namespace Characters
	{
		class Player;
	}
}

namespace GraphicalElements
{
	class Hud : public Ent
	{
	private:
		Managers::GraphicManager* pGraphicManager;
		Entities::Characters::Player* pPlayer;
		Math::CoordinateU windowSize;
		Heart* hearts;
		Text points;

	public:
		Hud(Entities::Characters::Player* pPlayer);
		virtual ~Hud();
		void setPlayer(Entities::Characters::Player* pPlayer);
		void render();
		void update(const float dt);
		void initialize();
		void updateHearts();
		void updatePoints();

	};
}