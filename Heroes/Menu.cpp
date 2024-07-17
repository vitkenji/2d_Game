#include "Menu.hpp"

namespace Menus
{
	Menu::Menu() : selected(0), min(0), max(2), menuControl(this), active(false)
	{
		Managers::GraphicManager* pG = Managers::GraphicManager::getInstance();
		back.initialize(BACKGROUND_PATH, Math::CoordinateF(pG->getWindowSize().x / 2, pG->getWindowSize().y / 2), Math::CoordinateF(pG->getWindowSize().x, pG->getWindowSize().y));

	}

	Menu::~Menu()
	{
		GraphicalElements::Button* button = nullptr;
		while (buttons.size() != 0)
		{
			button = buttons.back();
			delete(button);
			buttons.pop_back();
		}
		buttons.clear();
	}

	void Menu::updateView()
	{
		Managers::GraphicManager::getInstance()->centerView(Math::CoordinateF(Managers::GraphicManager::getInstance()->getWindowSize().x / 2, Managers::GraphicManager::getInstance()->getWindowSize().y / 2));
	}

	void Menu::selectUp()
	{
		if (active)
		{
			buttons[selected]->select(false);
			selected--;
		}
		if (selected < min)
		{
			selected = max;
		}
		buttons[selected]->select(true);
	}

	void Menu::selectDown()
	{
		if (active)
		{
			buttons[selected]->select(false);
			selected++;
		}
		if (selected > max)
		{
			selected = min;
		}
		buttons[selected]->select(true);
	}

}