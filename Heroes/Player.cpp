#include "Player.hpp"

namespace Entities
{
	namespace Characters
	{
		Player::Player() : Character(Math::CoordinateF(50, 50), Math::CoordinateF(50, 50), ID::player),
			isSprinting(false), isJumping(false), canJump(false)
		{
			swordDistance = 10;
			life = 50000;
			damage = 1;
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
			sprite.addNewAnimation(GraphicalElements::takeHit, PLAYER_TAKEHIT_PATH, 4, 1.6);
			sprite.addNewAnimation(GraphicalElements::jump, PLAYER_JUMP_PATH, 2, 1);
			sprite.addNewAnimation(GraphicalElements::fall, PLAYER_FALL_PATH, 2, 1);
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
			if (canJump)
			{
				isJumping = true;
				canJump = false;
				velocity.y = -sqrt(2 * GRAVITY * PLAYER_JUMP_HEIGHT);
			}
		}

		void Player::stopWalking()
		{
			this->isWalking = false;

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
				if (velocity.y < 0 && !canJump)
				{
					sprite.update(GraphicalElements::jump, isFacingRight(), position, dt);
				}
				else if(velocity.y > 0 && !canJump)
				{
					sprite.update(GraphicalElements::fall, isFacingRight(), position, dt);
				}
				else
				{
					sprite.update(GraphicalElements::idle, isFacingRight(), position, dt);
				}
			}

			else if (isWalking)
			{
				sprite.update(GraphicalElements::run, isFacingRight(), position, dt);
			}

			else if (isTakingHit)
			{
				sprite.update(GraphicalElements::takeHit, isFacingRight(), position, dt);
			}

			else
			{
				sprite.update(GraphicalElements::idle, isFacingRight(), position, dt);
			}
		}

		void Player::update(const float dt)
		{
			manageTakeHitCooldown(dt);

			position.y += velocity.y + (acceleration.y * dt * dt) / 2.0f;
			velocity.y += acceleration.y * dt;
		
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
			checkCollision(other, intersection);
			if (other->getID() == platform)
			{
				canJump = true;
				isJumping = false;
			}

			if (other->getID() == skeleton || other->getID() == goblin)
			{
				Character* pCharacter = dynamic_cast<Character*>(other);
				if (intersection.y < 0.f)
				{
					canJump = true;
					isJumping = false;
				}
				if (intersection.x < 0.f && pCharacter->getIsAttacking())
				{
					isTakingHit = true;
					takeDamage(pCharacter->getDamage());
				}
			}
		}

		void Player::checkCollision(Entity* other, Math::CoordinateF intersection)
		{
			if (other->getID() == platform)
			{		
				velocity.y = 0;	
			}

			if (other->getID() == skeleton || other->getID() == goblin)
			{
				if (intersection.x  + swordDistance< 0.f)
				{
					if (velocity.x > 0)
					{
						position.x -= 1;
					}
					else if (velocity.x < 0)
					{
						position.x += 1;
					}
					velocity.x = 0;

				}
				if (intersection.y < 0.f)
				{
					velocity.y = 0;
				}
			}
		}
	}
}