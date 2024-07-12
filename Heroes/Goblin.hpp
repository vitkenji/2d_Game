#pragma once
#include "Enemy.hpp"
#include "Bomb.hpp"
#include <list>

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			class Goblin : public Enemy
			{
			private:

			public:
				std::list<Projectiles::Bomb> bombList;
				std::list<Projectiles::Bomb>::iterator i;

				Goblin(Math::CoordinateF position);
				virtual ~Goblin();

				void addAnimations();
				void update(const float dt);

			};
		}
	}
}