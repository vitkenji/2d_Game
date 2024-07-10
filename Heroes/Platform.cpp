#include "Platform.hpp"

namespace Entities
{
	namespace Obstacles
	{
		Platform::Platform(Math::CoordinateF position) : StaticEntity(position, Math::CoordinateF(PLATFORM_WIDTH, PLATFORM_HEIGHT), platform)
		{
			initialize();
		}

		Platform::~Platform(){}

		void Platform::initialize()
		{
			sprite.initialize(PLATFORM_PATH, this->position, this->size);
		}
	}
}
