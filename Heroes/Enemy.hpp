#pragma once
#include "Character.hpp"

namespace Entities
{
	namespace Characters
	{
		namespace Enemies
		{
			class Enemy : public Character
			{
			protected:
			public:
				Enemy(Math::CoordinateF position, Math::CoordinateF size, ID id);
				~Enemy();
			};
		
		}
	}
}