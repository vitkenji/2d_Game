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
		for (int i = 0; i < staticEntities->getSize(); i++)
		{
			Math::CoordinateF distance; Math::CoordinateF intersection; Math::CoordinateF length;
			
			for (int j = 0; j < movingEntities->getSize(); j++)
			{
				distance.x = fabs((*staticEntities)[i]->getPosition().x - (*movingEntities)[j]->getPosition().x);
				distance.y = fabs((*staticEntities)[i]->getPosition().y - (*movingEntities)[j]->getPosition().y);

				length.x = ((*staticEntities)[i]->getSize().x / 2) + ((*movingEntities)[j]->getSize().x / 2);
				length.y = ((*staticEntities)[i]->getSize().y / 2) + ((*movingEntities)[j]->getSize().y / 2);

				if (length.x >= distance.x && length.y >= distance.y)
				{
					intersection = Math::CoordinateF(distance.x - length.x, distance.y - length.y);
					(*movingEntities)[j]->collide((*staticEntities)[i], intersection);

				}
			}
		}

		for (int i = 0; i < movingEntities->getSize(); i++)
		{
			Math::CoordinateF distance; Math::CoordinateF intersection; Math::CoordinateF length;
			
			for (int j = 0; j < movingEntities->getSize(); j++)
			{

				distance.x = fabs((*movingEntities)[i]->getPosition().x - (*movingEntities)[j]->getPosition().x + 1);
				distance.y = fabs((*movingEntities)[i]->getPosition().y - (*movingEntities)[j]->getPosition().y + 1);

				length.x = ((*movingEntities)[i]->getSize().x / 2) + ((*movingEntities)[j]->getSize().x / 2);
				length.y = ((*movingEntities)[i]->getSize().y / 2) + ((*movingEntities)[j]->getSize().y / 2);

				if (length.x > distance.x && length.y > distance.y)
				{
					intersection = Math::CoordinateF(distance.x - length.x, distance.y - length.y);
					if ((*movingEntities)[j] != (*movingEntities)[i])
					{
						(*movingEntities)[j]->collide((*movingEntities)[i], intersection);
						(*movingEntities)[i]->collide((*movingEntities)[j], intersection);
					}
				}
			}
		}
		clear();

	}


	void CollisionManager::clear()
	{
		
		Entities::MovingEntity* pAux = nullptr;
		for (int i = 0; i < movingEntities->getSize(); i++) {
			pAux = static_cast<Entities::MovingEntity*>((*movingEntities)[i]);
			if (pAux != nullptr) {
				if (!pAux->isActive()) {
					movingEntities->deleteEntity(pAux);
					i--;
					if (i < 0) { i = -1; }
				}
			}
		}
	}
}