#pragma once
#include "SFML/Graphics.hpp"
#include "Ent.hpp"

namespace Entities
{
	enum ID {
		player = 0,
		platform,
		skeleton,
		goblin
	};

	class Entity : public Ent
	{
	protected:
		ID id;
		float swordDistance;

	public:
		Entity(Math::CoordinateF position, Math::CoordinateF size, ID id);
		Entity();
		virtual ~Entity();

		void setID(ID id);
		ID getID() const;

		float getSwordDistance();

		virtual void render() = 0;
		virtual void update(const float dt) = 0;
		virtual void collide(Entity* other, Math::CoordinateF intersection) = 0;

	};
}