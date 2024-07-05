#include <SFML/Graphics.hpp>
#include "GraphicManager.hpp"
#include "MultiFrameAnimation.hpp"
#define PLAYER_IDLE_PATH "assets/players/player1_idle.png"
#define TICK_RATE 0.0078125

int main()
{
    float dt = 0;
    sf::Clock clock;
    clock.restart();
    Managers::GraphicManager* pGraphic = Managers::GraphicManager::getInstance();
    GraphicalElements::MultiFrameAnimation body;
    body.addNewAnimation(GraphicalElements::idle, PLAYER_IDLE_PATH, 8, 0.8);
    while (pGraphic->isWindowOpen())
    {
        sf::Event event;
        while (pGraphic->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                pGraphic->closeWindow();
        }

        if (dt < TICK_RATE) {
            dt += clock.getElapsedTime().asSeconds();
            clock.restart();
        } //
        else {
            dt -= TICK_RATE;
        }
        body.update(GraphicalElements::idle, false, Math::CoordinateF(200, 200), dt);
        body.render();
        pGraphic->display();
        pGraphic->clear();
    }

    return 0;
}