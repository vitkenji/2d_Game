#pragma once
#include "Enemy.hpp"

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
				Goblin(Math::CoordinateF position);
				~Goblin();
				void addAnimations();
				void update(const float dt);
				void updateSprite(const float dt);

			};
		}
	}
}