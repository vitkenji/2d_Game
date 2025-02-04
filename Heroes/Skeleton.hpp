#pragma once
#include "Enemy.hpp"
#include "Player.hpp"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			class Skeleton : public Enemy
			{
			private:
			
			public:
				Skeleton(Math::CoordinateF position);
				virtual ~Skeleton();

				void addAnimations();
				void update(const float dt);
				void walk();
				void noticePlayer(Math::CoordinateF distance);

			};
		}
	}
}