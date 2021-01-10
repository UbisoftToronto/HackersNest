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

    //Grabs how much time has passed since last frame
    const float dt = GameEngine::GameEngineMain::GetTimeDelta();


    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i position = sf::Mouse::getPosition(*GameEngine::GameEngineMain::GetInstance()->GetRenderWindow());
        float x = position.x;
        float y = position.y;
        std::cout << "x: ";
        std::printf("%.3f", x);
        std::cout << std::endl;
        std::cout << "y: ";
        std::printf("%.3f", y);
        std::cout << std::endl;
    }

}

void SortGarbageComponent::OnAddToWorld() {}
