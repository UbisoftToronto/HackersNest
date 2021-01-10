#include "WaterMovementComponent.h"
#include "GameEngine/GameEngineMain.h"
#include <SFML/Window/Keyboard.hpp>

using namespace Game;

void WaterMovementComponent::Update()
{
    Component::Update();

    //Grabs how much time has passed since last frame
    const float dt = GameEngine::GameEngineMain::GetTimeDelta();
    sf::Vector2f displacement;

    if ((GetEntity()->GetPos()).y < 955)
    {
        displacement = { 0.0f, 0.35f };
    }
    else
    {
        displacement = { 0.0f,0.0f };
    }

    //Update the entity position
    GetEntity()->SetPos(GetEntity()->GetPos() + displacement);
}

void WaterMovementComponent::OnAddToWorld() {}