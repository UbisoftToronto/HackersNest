#include "PlayerMovementComponent.h"
#include <SFML/Window/Keyboard.hpp>   //<-- Add the keyboard include in order to get keyboard inputs
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>
#include "GameEngine/GameEngineMain.h" //<-- Add this include to retrieve the delta time between frames

using namespace Game;

void PlayerMovementComponent::Update()
{
    Component::Update();

    //Grabs how much time has passed since last frame
    const float dt = GameEngine::GameEngineMain::GetTimeDelta();

    //By default the displacement is 0,0
    sf::Vector2f displacement{ 0.0f,0.0f };

    //The amount of speed that we will apply when input is received
    const float inputAmount = 100.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        displacement.x -= inputAmount * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        displacement.x += inputAmount * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        displacement.y += inputAmount * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        displacement.y -= inputAmount * dt;
    }

    //std::cout << sf::Mouse::getPosition().x << sf::Mouse::getPosition().y  << std::endl;
    sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition().x),  static_cast<float>(sf::Mouse::getPosition().y) };
    //sf::Window::getPosition();
    sf::Vector2f windowPos{ static_cast<float>(GetEntity()->window->getPosition().x),  static_cast<float>(GetEntity()->window->getPosition().y) };
    sf::Vector2f pos_diff = mousePos - GetEntity()->GetPos() - windowPos;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        displacement.x += pos_diff.x * dt;
        displacement.y += pos_diff.y * dt;
        GetEntity()->SetSize(100);
    }


    //Update the entity position
    GetEntity()->SetPos(GetEntity()->GetPos() + displacement);
}

void PlayerMovementComponent::OnAddToWorld() {}