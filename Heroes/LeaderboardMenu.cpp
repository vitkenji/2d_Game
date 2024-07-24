#include "LeaderboardMenu.hpp"

namespace Menus
{
	LeaderboardMenu::LeaderboardMenu(States::StateMachine* pStateMachine) : Menu(), States::State(pStateMachine, States::leaderboard)
	{
		GraphicalElements::Button* button = new GraphicalElements::Button(Math::CoordinateF((pGraphicManager->getWindowSize().x / 2) - 430, pGraphicManager->getWindowSize().y - 900), "RETURN");
		button->select(true);
		buttons.push_back(button);
		max = 0;
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
			changeState(States::mainMenu);
		}

	}

	void LeaderboardMenu::resetState()
	{
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

			text = new GraphicalElements::Text(Math::CoordinateF(pGraphicManager->getWindowSize().x / 2.0f, 400 + 40 * i), textString + pointsString, FONT2_PATH);
			text->setFontSize(48);
			text->setTextAlignment(GraphicalElements::center);
			text->setTextColor(77.6, 68.2, 44.3);
			ranking.push_back(text);

			file.close();

		}

	}

}