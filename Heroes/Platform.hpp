#pragma once
#include "StaticEntity.hpp"

namespace Entities
{
	namespace Obstacles
	{
		class Platform : public StaticEntity
		{
		private:

		public:
			Platform(Math::CoordinateF position);
			virtual ~Platform();

			void initialize();
		};
	}
}