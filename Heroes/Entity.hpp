#pragma once
#include "SFML/Graphics.hpp"
#include "Ent.hpp"

namespace Entities
{
	enum ID {
		player = 0,
		platform,
		skeleton,
		goblin,
		mushroom,
		flyingeye,
		boss,
		bomb,
		fire,
		water,
		mud,
		box
	};

	class Entity : public Ent
	{
	protected:
		ID id;
		bool active;
		float swordDistance;

	public:
		Entity(Math::CoordinateF position, Math::CoordinateF size, ID id);
		virtual ~Entity();

		void setID(ID id);
		ID getID() const;

		void setActive(bool active);
		bool isActive();
		float getSwordDistance();

		virtual void render() = 0;
		virtual void update(const float dt) = 0;
		virtual void collide(Entity* other, Math::CoordinateF intersection) = 0;

	};
}