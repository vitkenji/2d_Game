#pragma once
#include "EntityList.hpp"
#include "MovingEntity.hpp"
#include "StaticEntity.hpp"

namespace Managers
{
	class CollisionManager
	{
	private:
		List::EntityList* movingEntities;
		List::EntityList* staticEntities;

	public:
		CollisionManager(List::EntityList* movingEntities, List::EntityList* staticEntities);
		~CollisionManager();
		void collide();
		void clear();
	};
}