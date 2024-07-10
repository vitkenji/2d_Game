#include "CollisionManager.hpp"

namespace Managers
{
	CollisionManager::CollisionManager(List::EntityList* movingEntities, List::EntityList* staticEntities) : 
		movingEntities(movingEntities), staticEntities(staticEntities)
	{

	}

	CollisionManager::~CollisionManager()
	{

	}

	void CollisionManager::collide()
	{
		Entities::Entity* ent1 = nullptr;
		Entities::Entity* ent2 = nullptr;
		Math::CoordinateF intersection;
		Math::CoordinateF centerDistance;
		
		for (int i = 0; i < movingEntities->getSize(); i++)
		{
			for (int j = 0; j < movingEntities->getSize(); j++)
			{

			}
		}

		for (int i = 0; i < movingEntities->getSize(); i++)
		{
			for (int j = 0; j < staticEntities->getSize(); j++)
			{

			}
		}

	}
}