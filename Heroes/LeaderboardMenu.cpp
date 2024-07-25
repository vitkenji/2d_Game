#include "LeaderboardMenu.hpp"

namespace Menus
{
	float cooldown = 0;
	LeaderboardMenu::LeaderboardMenu(States::StateMachine* pStateMachine) : Menu(), States::State(pStateMachine, States::StateID::leaderboard), 
		title(Math::CoordinateF(300, 300), "HEROES", FONT2_PATH)
	{
		active = false;
		Managers::GraphicManager* pGraphicManager = Managers::GraphicManager::getInstance();

		active = false;
		GraphicalElements::Button* button = new GraphicalElements::Button(Math::CoordinateF((pGraphicManager->getWindowSize().x / 2) - 430, pGraphicManager->getWindowSize().y - 900), "RETURN");
		button->select(true);
		buttons.push_back(button);
		max = 0;

		title.setFontSize(90);
		title.setTextInfo("HIGH SCORES");
		title.setTextColor(0, 0, 0);
		title.setTextAlignment(GraphicalElements::TextAlignment::center);
		title.setPosition(Math::CoordinateF(pGraphicManager->getWindowSize().x / 2.0f, pGraphicManager->getWindowSize().y / 2 - 250));

	}

	LeaderboardMenu::~LeaderboardMenu()
	{

	}

	void LeaderboardMenu::update(const float dt)
	{
		active = true;
	}

	void LeaderboardMenu::render()
	{
		updateView();
		back.render();
		title.render();
		for (i = buttons.begin(); i != buttons.end(); i++)
		{
			(*i)->render();
		}
		for (it = ranking.begin(); it != ranking.end(); it++)
		{
			(*it)->render();
		}
	}

	void LeaderboardMenu::execute()
	{
		if (active)
		{
			active = false;
			switch (selected) {
			case 0:
				changeState(States::StateID::mainMenu);
				break;
			default:
				break;
			}
		}

	}

	void LeaderboardMenu::resetState()
	{
		active = false;
		buttons[0]->select(true);
		for (it = ranking.begin(); it != ranking.end(); it++)
		{
			delete (*it);
		}
		ranking.clear();
		buildLeaderboard();
	}

	void LeaderboardMenu::buildLeaderboard()
	{
		std::ifstream file;
		file.open(LEADERBOARD_PATH, std::ios::binary | std::ios::in);

		if (!file)
		{
			std::ofstream writeFile(LEADERBOARD_PATH, std::ios::out | std::ios::trunc);
			writeFile.close();
		}

		int points;
		std::string name;
		std::string textString;
		std::string pointsString;

		GraphicalElements::Text* text;

		for (int i = 0; i < 10; i++)
		{
			name = "";
			points = 0;
			pointsString = "";

			std::getline(file, pointsString);
			std::getline(file, name);

			textString = std::to_string((i + 1) / 10) + std::to_string((i + 1) % 10) + " - " + name + " ";

			if (pointsString.length() > 0) {

				points = std::stoi(pointsString);

				pointsString = std::to_string(points / 1000000);
				points %= 1000000;

				pointsString += std::to_string(points / 100000);
				points %= 100000;

				pointsString += std::to_string(points / 10000);
				points %= 10000;

				pointsString += std::to_string(points / 1000);
				points %= 1000;

				pointsString += std::to_string(points / 100);
				points %= 100;

				pointsString += std::to_string(points / 10);
				points %= 10;

				pointsString += std::to_string(points);
			}

			while (textString.length() + pointsString.length() < 50)
			{
				textString += ".";
			}

			text = new GraphicalElements::Text(Math::CoordinateF(Managers::GraphicManager::getInstance()->getWindowSize().x / 2.0f, 400 + 40 * i), textString + pointsString, FONT1_PATH);
			text->setFontSize(20);
			text->setTextAlignment(GraphicalElements::center);
			text->setTextColor(77.6, 68.2, 44.3);
			ranking.push_back(text);

			file.close();

		}

	}

}