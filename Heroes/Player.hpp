#pragma once
#include "Character.hpp"
#include "PlayerControl.hpp"

namespace Entities
{
	namespace Characters
	{
		class Player : public Character
		{
		protected:
			bool isJumping;
			bool canJump;

		public:
			Player();
			virtual ~Player();

			void attack();
			void jump();
			void walk(bool right);
			void sprint();
			void limitSprint();

			void stopWalking();
			void stopAttacking();

			void addAnimations();
			void updateSprite(const float dt);
			void update(const float dt);

			void collide(Entity* other, Math::CoordinateF intersection);
			void checkCollision(Entity* other, Math::CoordinateF intersection);
		};
	}
}