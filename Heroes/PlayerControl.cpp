#include "Player.hpp"
#include "PlayerControl.hpp"

namespace Control
{
	PlayerControl::PlayerControl(Entities::Characters::Player* pPlayer) : Observer(), pPlayer(pPlayer), keysPressed()
	{
		jump = "W";
		left = "A";
		right = "D";
		attack = "Space";
		sprint = "Shift";
		
		insertKeysPressed();
	}

	PlayerControl::~PlayerControl()
	{
		this->pPlayer = nullptr;
	}

	void PlayerControl::notifyPressed(std::string key)
	{
		keysPressed[key] == true;

		if (key == "Space") { pPlayer->attack(); }
		else if (key == "W") { pPlayer->jump(); }
		else if (key == "D") { pPlayer->walk(true); }
		else if (key == "A") { pPlayer->walk(false); }
		else if (key == "Shift") { pPlayer->sprint(); }

	}

	void PlayerControl::notifyReleased(std::string key)
	{
		keysPressed[key] == false;

		if (key == "Space") { pPlayer->stopAttacking(); }
		else if (key == "D") { pPlayer->stopWalking(); }
		else if (key == "A") { pPlayer->stopWalking(); }

	}

	void PlayerControl::setPlayer(Entities::Characters::Player* pPlayer)
	{
		this->pPlayer = pPlayer;

	}

	void PlayerControl::setKeys(std::string jump, std::string left, std::string right, std::string attack, std::string sprint)
	{
		this->jump = jump;
		this->left = left;
		this->right = right;
		this->attack = attack;
	}

	void PlayerControl::insertKeysPressed()
	{
		keysPressed.insert(std::pair<std::string, bool>(jump, false));
		keysPressed.insert(std::pair<std::string, bool>(left, false));
		keysPressed.insert(std::pair<std::string, bool>(right, false));
		keysPressed.insert(std::pair<std::string, bool>(attack, false));
		keysPressed.insert(std::pair<std::string, bool>(sprint, false));

	}

}