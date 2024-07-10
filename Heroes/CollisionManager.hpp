#pragma once
#include "EntityList.hpp"

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