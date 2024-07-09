#include "EventManager.hpp"

namespace Managers
{
	EventManager* EventManager::instance = nullptr;
	
	EventManager* EventManager::getInstance()
	{
		if (instance == nullptr)
		{
			instance = new EventManager();
		}
		return instance;

	}
	
	EventManager::EventManager() : pGraphic(GraphicManager::getInstance()),pInput(InputManager::getInstance()), window(nullptr)
	{
		window = pGraphic->getWindow();
	}

	EventManager::~EventManager()
	{
		window = nullptr;
	}

	void EventManager::pollEvents()
	{
		sf::Event event;
		
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				pGraphic->closeWindow();
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				pInput->handleKeyPressed(event.key.code);
				
			}
			else if (event.type == sf::Event::KeyReleased)
			{
				pInput->handleKeyReleased(event.key.code);
			
			}

		}
	}
}