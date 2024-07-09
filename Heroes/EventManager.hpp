#pragma once
#include "GraphicManager.hpp"
#include "EventManager.hpp"
#include "InputManager.hpp"

namespace Managers
{
	class EventManager
	{
	private:
		GraphicManager* pGraphic;
		InputManager* pInput;
		sf::RenderWindow* window;
		static EventManager* instance;
		EventManager();

	public:
		~EventManager();
		static EventManager* getInstance();
		void pollEvents();
	};
}