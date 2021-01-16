#include "PlayerMovementComponent.h"
#include <SFML/Window/Keyboard.hpp>   //<-- Add the keyboard include in order to get keyboard inputs
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>
#include <math.h>
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
    const float inputAmount = 50.0f;

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

    sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition().x),  static_cast<float>(sf::Mouse::getPosition().y) };
    sf::Vector2f windowPos{ static_cast<float>(GetEntity()->window->getPosition().x),  static_cast<float>(GetEntity()->window->getPosition().y) };
    

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        destination_x = mousePos.x;
        destination_y = mousePos.y;
    }
    sf::Vector2f destination{ destination_x, destination_y };
    sf::Vector2f pos_diff = destination - GetEntity()->GetPos() - windowPos;

    // Find the length of the pos_diff vector
    float vector_length = sqrt(pos_diff.x * pos_diff.x + pos_diff.y * pos_diff.y);

    displacement.x += inputAmount * (pos_diff.x / vector_length) * dt;
    displacement.y += inputAmount * (pos_diff.y / vector_length) * dt;
    
    //Update the entity position
    GetEntity()->SetPos(GetEntity()->GetPos() + displacement);
}

void PlayerMovementComponent::OnAddToWorld() {}