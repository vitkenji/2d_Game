#include "Player.hpp"

namespace Entities
{
	namespace Characters
	{
		Player::Player() : Character(Math::CoordinateF(50, 50), Math::CoordinateF(50, 50),ID::player),
			isWalking(false), isSprinting(false), isJumping(false), isAttacking(false), canJump(true)
		{
			velocity.y = 0.5;
			addAnimations();
			setFacingRight(true);
		}

		Player::~Player()
		{
		}

		void Player::addAnimations()
		{
			sprite.addNewAnimation(GraphicalElements::idle, PLAYER_IDLE_PATH, 8, 0.9);
			sprite.addNewAnimation(GraphicalElements::attack, PLAYER_ATTACK_PATH, 6, 0.9);
			sprite.addNewAnimation(GraphicalElements::run, PLAYER_RUN_PATH, 8, 0.9);
			sprite.addNewAnimation(GraphicalElements::takeHit, PLAYER_TAKEHIT_PATH, 4, 0.9);
			sprite.addNewAnimation(GraphicalElements::jump, PLAYER_JUMP_PATH, 2, 0.9);
			sprite.addNewAnimation(GraphicalElements::fall, PLAYER_FALL_PATH, 2, 0.9);
		}

		void Player::attack()
		{
			isWalking = false;
			isAttacking = true;
		}

		void Player::walk(bool right)
		{
			if (right) { velocity.x = PLAYER_VELOCITY_X; }
			else { velocity.x = -PLAYER_VELOCITY_X; }
			setFacingRight(right);
			isWalking = true;
			isAttacking = false;
		}

		void Player::sprint()
		{
			velocity.x *= 1.5;
			isSprinting = true;
		}

		void Player::jump()
		{
			isJumping = true;
			canJump = false;
		}

		void Player::stopWalking()
		{
			this->isWalking = false;
		}

		void Player::stopJumping()
		{
			this->isJumping = false;
		}

		void Player::stopAttacking()
		{
			this->isAttacking = false;
		}

		void Player::stopSprinting()
		{
			this->isSprinting = false;
		}


		void Player::updateSprite(const float dt)
		{
			if(isAttacking)
			{
				sprite.update(GraphicalElements::attack, isFacingRight(), position, dt);
			}
			else if (isJumping)
			{
				sprite.update(GraphicalElements::jump, isFacingRight(), position, dt);
			}
			else if (isWalking)
			{
				sprite.update(GraphicalElements::run, isFacingRight(), position, dt);
			}
			else
			{
				sprite.update(GraphicalElements::idle, isFacingRight(), position, dt);
			}
		}

		void Player::update(const float dt)
		{
			if (velocity.y != 0)
			{
				position.y += velocity.y + (GRAVITY * dt * dt) / 2.0f;
				velocity.y += GRAVITY * dt;
			}

			if (isWalking)
			{
				position.x += velocity.x * dt;
			}
			limitSprint();
			
			updateSprite(dt);
		}

		void Player::limitSprint()
		{
			if (velocity.x >= 100)
			{
				velocity.x = 100;
				//stopWalking();
			}
			else if (velocity.x <= -100)
			{
				velocity.x = -100;
				//stopWalking();
			}
		}

		void Player::collide(Entity* other, Math::CoordinateF intersection)
		{
			if (other->getID() == platform)
			{

				velocity.y = 0;
			}
		}


	}
}