#pragma once
#include "MovingEntity.hpp"

namespace Entities
{
	namespace Characters
	{
		class Character : public MovingEntity
		{
		protected:
			int life;

		public:
			Character(Math::CoordinateF position, Math::CoordinateF size, ID id);
			~Character();
		
		};
	}
}