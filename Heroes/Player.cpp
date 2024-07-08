#include "Player.hpp"

namespace Entities
{
	namespace Characters
	{
		Player::Player() : Character(Math::CoordinateF(50, 50), Math::CoordinateF(50, 50),ID::player)
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
	}
}