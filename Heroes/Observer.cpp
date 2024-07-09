#include "Observer.hpp"

namespace Control
{
	Observer::Observer()
	{
		this->pInput = Managers::InputManager::getInstance();
		pInput->attach(this);
	}

	Observer::~Observer()
	{
		pInput->detach(this);
	}
}