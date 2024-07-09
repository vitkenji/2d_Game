#include "Player.hpp"

namespace Entities
{
	namespace Characters
	{
		Player::Player() : Character(Math::CoordinateF(50, 50), Math::CoordinateF(50, 50),ID::player),
			isWalking(false), isSprinting(false), isJumping(false), isAttacking(false), canJump(true)
		{
			addAnimations();
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
			isAttacking = true;
		}

		void Player::walk()
		{
			isWalking = true;
		}

		void Player::sprint()
		{
			isSprinting = true;
		}

		void Player::jump()
		{
			isJumping = true;
			canJump = false;
		}

		void Player::stopWalking()
		{
			isWalking = false;
		}

		void Player::stopJumping()
		{
			isJumping = false;
		}

		void Player::stopAttacking()
		{
			isAttacking = false;
		}

		void Player::stopSprinting()
		{
			isSprinting = false;
		}


		void Player::updateSprite(const float dt)
		{
			if(isAttacking)
			{
				sprite.update(GraphicalElements::attack, true, Math::CoordinateF(50, 50), dt);
			}
			else if (isJumping)
			{
				sprite.update(GraphicalElements::jump, true, Math::CoordinateF(50, 50), dt);
			}
			else if (isWalking)
			{
				sprite.update(GraphicalElements::run, true, Math::CoordinateF(50, 50), dt);
			}
			else
			{
				sprite.update(GraphicalElements::idle, true, Math::CoordinateF(50, 50), dt);
			}
		}

		void Player::update(const float dt)
		{
			updateSprite(dt);
		}

	}
}