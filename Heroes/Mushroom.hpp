#include "Enemy.hpp"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			class Mushroom : public Enemy
			{
			private:

			public:
				Mushroom(Math::CoordinateF position);
				virtual ~Mushroom();
				void addAnimations();
				void update(const float dt);
				void walk();
				void noticePlayer(Math::CoordinateF distance);
			};
		}
	}
}