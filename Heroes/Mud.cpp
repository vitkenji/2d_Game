#include "Mud.hpp"

namespace Entities
{
	namespace Obstacles
	{
		Mud::Mud(Math::CoordinateF position) : StaticEntity(position, Math::CoordinateF(MUD_WIDTH, MUD_HEIGHT), mud)
		{
			initialize();
		}

		Mud::~Mud()
		{

		}

		void Mud::initialize()
		{
			sprite.initialize(MUD_PATH, this->position, this->size);
		}


	}
}