#include "MainMenu.hpp"
#include "Game.hpp"

namespace Menus
{
	Managers::GraphicManager* pG = Managers::GraphicManager::getInstance();

	MainMenu::MainMenu(States::Game* pGame) : Menu(), States::State(static_cast<States::StateMachine*>(pGame), States::StateID::mainMenu), pGame(pGame),
		title(Math::CoordinateF(pG->getWindowSize().x / 2.0f, pG->getWindowSize().y / 2), "HEROES")
	{

		GraphicalElements::Button* button = nullptr;
		button = new GraphicalElements::Button(Math::CoordinateF(pG->getWindowSize().x / 2.0f, pG->getWindowSize().y / 2 + 100), "SINGLEPLAYER");
		button->select(true);
		buttons.push_back(button);

		button = new GraphicalElements::Button(Math::CoordinateF(pG->getWindowSize().x / 2.0f, pG->getWindowSize().y / 2 + 200), "MULTIPLAYER");
		button->select(false);
		buttons.push_back(button);

		title.setFontSize(FONT_SIZE);
		title.setTextInfo("HEROES");
		title.setTextColor(255, 255 ,255);
		title.setTextAlignment(GraphicalElements::TextAlignment::center);
		title.setPosition(Math::CoordinateF(pG->getWindowSize().x / 2, title.getSize().y / 2));

		max = 3;

	}

	MainMenu::~MainMenu()
	{

	}

	void MainMenu::update(const float dt)
	{
		active = true;
		if (title.getPosition().y < 200)
		{
			title.setPosition(Math::CoordinateF(title.getPosition().x, title.getPosition().y + 1));
		}

	}
	void MainMenu::render()
	{
		updateView();
		//back.render();
		for (i = buttons.begin(); i != buttons.end(); i++)
		{
			(*i)->render();
		}
		title.render();
	}
	void MainMenu::resetState()
	{
		title.setPosition(Math::CoordinateF(title.getPosition().x, 0.0f - title.getSize().y / 2));
	}
	void MainMenu::execute()
	{

	}
}