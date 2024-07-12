#pragma once
#include <list>
#include <map>
#include <SFML/Graphics.hpp>
#include <string>

namespace Control
{
	class Observer;
}

namespace Managers
{
	class InputManager
	{
	private:
		std::list<Control::Observer*> observing;
		std::list<Control::Observer*>::iterator i;
		std::map<sf::Keyboard::Key, std::string> keyMap;
		static InputManager* instance;

		InputManager();

	public:
		~InputManager();

		static InputManager* getInstance();
		void attach(Control::Observer* pObserver);
		void detach(Control::Observer* pObserver);
		void handleKeyPressed(sf::Keyboard::Key key);
		void handleKeyReleased(sf::Keyboard::Key key);
		std::string getKeyAsString(sf::Keyboard::Key key);

	};
}