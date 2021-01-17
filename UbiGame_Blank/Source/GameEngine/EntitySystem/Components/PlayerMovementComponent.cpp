#pragma once
#include "PlayerMovementComponent.h"
#include <SFML/Window/Keyboard.hpp>   //<-- Add the keyboard include in order to get keyboard inputs
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>
#include <math.h>
#include "../../GameEngineMain.h" //<-- Add this include to retrieve the delta time between frames

using namespace Game;

void PlayerMovementComponent::Update()
{
    Component::Update();

    //Grabs how much time has passed since last frame
    const float dt = GameEngine::GameEngineMain::GetTimeDelta();

    //By default the displacement is 0,0
    sf::Vector2f displacement{ 0.0f,0.0f };

    //The amount of speed that we will apply when input is received
    float inputAmount = 50.0f;

    sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition().x),  static_cast<float>(sf::Mouse::getPosition().y) };
    sf::Vector2f windowPos{ static_cast<float>(GetEntity()->window->getPosition().x),  static_cast<float>(GetEntity()->window->getPosition().y) };

    sf::Vector2f destination{ destination_x, destination_y };
    sf::Vector2f pos_diff = destination - GetEntity()->GetPos() - windowPos;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        destination_x = mousePos.x;
        destination_y = mousePos.y;

        pos_diff = destination - GetEntity()->GetPos() - windowPos;

        sf::Vector2f unit{0.f,1.f};

        float dot = pos_diff.x*unit.x + pos_diff.y*unit.y;
        float det = pos_diff.x*unit.y - pos_diff.y*unit.x;
        float angle = 180*atan(dot/det)/3.14;
        if (pos_diff.x < 0){
            angle += 180;
        }
        GetEntity()->SetRotation(angle);
    }

    destination.x = destination_x;
    destination.y = destination_y;



    // Find the length of the pos_diff vector
    float vector_length = sqrt(pos_diff.x * pos_diff.x + pos_diff.y * pos_diff.y);

    if (GetEntity()->isAbility) {
        inputAmount = 0.f;
    }

    if (abs(vector_length) < 1) {
        vector_length = 1.f;
    }


    displacement.x += inputAmount * (pos_diff.x / vector_length) * dt;
    displacement.y += inputAmount * (pos_diff.y / vector_length) * dt;
    
    //Update the entity position
    GetEntity()->SetPos(GetEntity()->GetPos() + displacement);
}

void PlayerMovementComponent::OnAddToWorld() {}