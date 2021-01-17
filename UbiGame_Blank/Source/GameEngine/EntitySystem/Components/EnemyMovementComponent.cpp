#pragma once
#include "EnemyMovementComponent.h"
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "../../GameEngineMain.h" //<-- Add this include to retrieve the delta time between frames

using namespace Game;

void EnemyMovementComponent::Update()
{
    Component::Update();
    //Grabs how much time has passed since last frame
    const float dt = GameEngine::GameEngineMain::GetTimeDelta();
    timer -= dt;
    if(timer - dt <= 0){
        timer = (float)(rand() % 5);
        destination_x = (float)(rand() % 500 + 200);
        destination_y = (float)(rand() % 500 + 200);//random position on screen
    }

    //By default the displacement is 0,0
    sf::Vector2f displacement{ 0.0f,0.0f };

    //The amount of speed that we will apply when input is received
    float inputAmount = 50.0f;

    
    
    

    sf::Vector2f destination{ destination_x, destination_y };
    // if(GetEntity()->hookDown <= 0){ //If the hook is ready and not on cooldown, comment this in and out to enable smart targeting or random
    //     destination = player->GetPos();
    // }
    sf::Vector2f pos_diff = destination - GetEntity()->GetPos();

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

    sf::Vector2f unit{0.f,1.f};

    float dot = pos_diff.x*unit.x + pos_diff.y*unit.y;
    float det = pos_diff.x*unit.y - pos_diff.y*unit.x;
    float angle = 180*atan(dot/det)/3.14;
    if (pos_diff.x < 0){
        angle += 180;
    }
    GetEntity()->SetRotation(angle);

}

void EnemyMovementComponent::OnAddToWorld() {}