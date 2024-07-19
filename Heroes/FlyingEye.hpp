#include "Enemy.hpp"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			class FlyingEye : public Enemy
			{
			private:
				float bombCooldown;
				float attackAnimationTime;
				bool canShoot;

			public:
				FlyingEye(Math::CoordinateF position);
				virtual ~FlyingEye();

				void addAnimations();
				void update(const float dt);
				void shoot(const float dt);
				void noticePlayer(Math::CoordinateF distance);
				void collide(Entity* other, Math::CoordinateF intersection);

			};
		}
	}
}