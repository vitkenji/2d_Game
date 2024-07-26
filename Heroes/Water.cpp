#include "Water.hpp"

namespace Entities
{
	namespace Obstacles
	{
		Water::Water(Math::CoordinateF position) : StaticEntity(position, Math::CoordinateF(WATER_WIDTH, WATER_HEIGHT), water), rapidness(4)
		{
			initialize();
		}

		Water::~Water()
		{

		}

		void Water::initialize()
		{
			sprite.initialize(WATER_PATH, this->position, this->size);
		}
	}
}