#pragma once
#include "StaticEntity.hpp"

namespace Entities
{
	namespace Obstacles
	{
		class Mud : public StaticEntity
		{
		private:
		public:
			Mud(Math::CoordinateF position);
			virtual ~Mud();
			void initialize();
		};
	}
}