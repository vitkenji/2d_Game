#include "Player.hpp"
#include "Fire.hpp"

namespace Entities
{
	namespace Characters
	{
		Player::Player() : Character(Math::CoordinateF(50, 600), Math::CoordinateF(PLAYER_SIZE_X, PLAYER_SIZE_Y), ID::player),
		 isJumping(false), canJump(false)
		{
			swordDistance = 10;
			life = 50000;
			damage = 16;
			addAnimations();
			setFacingRight(true);
		}

		Player::~Player()
		{
		}

		void Player::addAnimations()
		{
			sprite.addNewAnimation(GraphicalElements::idle, PLAYER_IDLE_PATH, 8, 0.1);
			sprite.addNewAnimation(GraphicalElements::attack, PLAYER_ATTACK_PATH, 6, 0.1);
			sprite.addNewAnimation(GraphicalElements::run, PLAYER_RUN_PATH, 8, 0.1);
			sprite.addNewAnimation(GraphicalElements::takeHit, PLAYER_TAKEHIT_PATH, 4, 0.21);
			sprite.addNewAnimation(GraphicalElements::jump, PLAYER_JUMP_PATH, 2, 0.1);
			sprite.addNewAnimation(GraphicalElements::fall, PLAYER_FALL_PATH, 2, 0.1);
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
	
			if (isWalking)
			{
				position.x += velocity.x * dt;
			}

			limitSprint();
			fallToGravity(dt);
			updateSprite(dt);
		}

		void Player::limitSprint()
		{
			if (velocity.x >= 500)
			{
				velocity.x = 500;
			}
			else if (velocity.x <= -500)
			{
				velocity.x = -500;
				
			}
		}

		void Player::collide(Entity* other, Math::CoordinateF intersection)
		{
			checkCollision(other, intersection);
			if (other->getID() == platform || other->getID() == box)
			{
				canJump = true;
				isJumping = false;
			}

			if (other->getID() == fire)
			{
				MovingEntity* pFire = dynamic_cast<MovingEntity*>(other);
				if (intersection.x < 0.f)
				{
					isTakingHit = true;
					takeDamage(pFire->getDamage());
				}
			}

			if (other->getID() == skeleton || other->getID() == goblin || other->getID() == mushroom)
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
			if (other->getID() == box)
			{
				if (intersection.y < 0.f)
				{
					velocity.y = 0;
				}
				if (intersection.x < 0.f)
				{
					velocity.x = PLAYER_VELOCITY_X / 5;
					if (!facingRight)
					{
						velocity.x *= -1;
					}
				}
			}
		}
	}
}