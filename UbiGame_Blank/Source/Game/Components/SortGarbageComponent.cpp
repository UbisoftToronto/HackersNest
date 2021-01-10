#include "SortGarbageComponent.h"
#include "GameEngine/GameEngineMain.h"
#include <SFML/Window/Mouse.hpp>
#include <string>
#include <iostream>
#include <cstdio>

using namespace Game;

void SortGarbageComponent::Update()
{
    Component::Update();

    const int numSides = 4;

    int garbage[numSides] = { 1375 - 175/2, 1375 + 175 / 2, 550 -175/2, 550 + 175 / 2 };
    int compost[numSides] = { 1400 - 175 / 2, 1400 + 175 / 2, 720 - 175 / 2, 720 + 175 / 2 };
    int recycling[numSides] = { 1400 - 175 / 2, 1400 + 175 / 2, 900 - 175 / 2, 900 + 175 / 2 };

    int alCan[numSides] = { 650 - 150/2, 650 + 150 / 2, 600 - 150 / 2, 600 + 150 / 2 };
    int banana[numSides] = { 600 - 170 / 2, 600 + 170 / 2, 750 - 150 / 2, 750 + 150 / 2 };
    int bottle[numSides] = { 850 - 90 / 2, 850 + 90 / 2, 850 - 150 / 2, 850 + 150 / 2 };
    int chips[numSides] = { 450 - 130 / 2, 450 + 130 / 2, 650 - 130 / 2, 650 + 150 / 2 };
    int fish[numSides] = { 800 - 170 / 2, 800 + 170 / 2, 720 - 80 / 2, 720 + 80 / 2 };
    int garbageBall[numSides] = { 470 - 130 / 2, 470 + 130 / 2, 900 - 150 / 2, 900 + 150 / 2 };

    std::string clicked = "none";
    std::string last = "none";

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i position = sf::Mouse::getPosition(*GameEngine::GameEngineMain::GetInstance()->GetRenderWindow());
        int x = (int)position.x;
        int y = (int)position.y;

        if (x > garbage[0] && x < garbage[1] && y > garbage[2] && y < garbage[3]) {
            //GetSortGarbageEntity()->SetGarbageClicked(true);
            std::cout << "\ngarbage";
        }
        if (x > compost[0] && x < compost[1] && y > compost[2] && y < compost[3]) {
            std::cout << "\ncompost";
        }
        if (x > recycling[0] && x < recycling[1] && y > recycling[2] && y < recycling[3])
            std::cout << "\nrecycling";
        if (x > alCan[0] && x < alCan[1] && y > alCan[2] && y < alCan[3])
            std::cout << "\nalCan";
        if (x > banana[0] && x < banana[1] && y > banana[2] && y < banana[3])
            std::cout << "\nbanana";
        if (x > bottle[0] && x < bottle[1] && y > bottle[2] && y < bottle[3])
            std::cout << "\nbottle";
        if (x > chips[0] && x < chips[1] && y > chips[2] && y < chips[3])
            std::cout << "\nchips";
        if (x > fish[0] && x < fish[1] && y > fish[2] && y < fish[3])
            std::cout << "\nfish";
        if (x > garbageBall[0] && x < garbageBall[1] && y > garbageBall[2] && y < garbageBall[3])
            std::cout << "\ngarbageBall";

    }

}

void SortGarbageComponent::OnAddToWorld() {}
