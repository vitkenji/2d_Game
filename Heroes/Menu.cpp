#include "Menu.hpp"

namespace Menus
{
	Menu::Menu() : selected(0), min(0), max(2), menuControl(this), active(false), pGraphicManager(Managers::GraphicManager::getInstance())
	{
		Managers::GraphicManager* pGraphicManager = Managers::GraphicManager::getInstance();
		back.initialize(MAINMENUBACKGROUND_PATH, Math::CoordinateF(pGraphicManager->getWindowSize().x / 2, pGraphicManager->getWindowSize().y / 2), Math::CoordinateF(pGraphicManager->getWindowSize().x, pGraphicManager->getWindowSize().y));
		menuControl = Control::MenuControl(this);

		if (!buttonBuffer.loadFromFile(BUTTON_SOUND_PATH))
		{
			std::cout << "error loading button sound" << std::endl;
			exit(1);
		}
		buttonSound.setBuffer(buttonBuffer);

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
		if (active && selected > min)
		{
			buttons[selected]->select(false);
			buttons[selected]->raiseTextPosition();
			selected--;
			buttons[selected]->lowerTextPosition();
			buttonSound.play();
		}

		buttons[selected]->select(true);
	}

	void Menu::selectDown()
	{
		if (active && selected < max)
		{
			buttons[selected]->select(false);
			buttons[selected]->raiseTextPosition();
			selected++;
			buttons[selected]->lowerTextPosition();
			buttonSound.play();
		}
		buttons[selected]->select(true);
	}

}