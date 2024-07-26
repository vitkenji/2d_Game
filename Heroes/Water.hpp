#pragma once
#include "StaticEntity.hpp"

namespace Entities
{
	namespace Obstacles
	{
		class Water : public StaticEntity
		{
		private:
			float rapidness;

		public:
			Water(Math::CoordinateF position);
			virtual ~Water();
			void initialize();
		};
	}
}