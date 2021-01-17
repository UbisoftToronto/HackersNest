#include "HookComponent.h"
#include <SFML/Window/Keyboard.hpp>   //<-- Add the keyboard include in order to get keyboard inputs
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>
#include "GameEngine/GameEngineMain.h" //<-- Add this include to retrieve the delta time between frames
#include "PlayerMovementComponent.h"
#include "PlayerAbilityComponent.h"
#include <math.h>

using namespace Game;

void HookComponent::Update()
{
    Component::Update();

    //Grabs how much time has passed since last frame
    const float dt = GameEngine::GameEngineMain::GetTimeDelta();

        //By default the displacement is 0,0
    sf::Vector2f displacement{ 0.0f,0.0f };

    //The amount of speed that we will apply when input is received
    float inputAmount = 105.0f;

    if (liveTime > 0) {
        displacement.x += inputAmount * destination_x * dt;
        displacement.y += inputAmount * destination_y * dt;
        liveTime -= dt;
    } else if (retractTime > -0.25f) {
        displacement.x -= inputAmount * destination_x * dt;
        displacement.y -= inputAmount * destination_y * dt;
        retractTime -= dt;
    } else {
        GameEngine::GameEngineMain::GetInstance()->RemoveEntity(GetEntity());
    }
    GetEntity()->SetPos(GetEntity()->GetPos() + displacement);
}

void HookComponent::OnAddToWorld() {}