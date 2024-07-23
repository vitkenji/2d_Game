#pragma once
#include "InputManager.hpp"
#include "std.h"

namespace Control
{
	class Observer
	{
	protected:
		Managers::InputManager* pInput;

	public:
		Observer();
		~Observer();

		virtual void notifyPressed(std::string key) = 0;
		virtual void notifyReleased(std::string key) = 0;

	};
}
