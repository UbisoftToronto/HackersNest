#include "HandPlayerMovementComponent.h"
#include "GameEngine/GameEngineMain.h"
#include <SFML/Window/Keyboard.hpp>

using namespace Game;

void HandPlayerMovementComponent::Update()
{
    Component::Update();

    //Grabs how much time has passed since last frame
    const float dt = GameEngine::GameEngineMain::GetTimeDelta();

    //By default the displacement is 0,0
    sf::Vector2f displacement{ 0.0f,0.0f };

    //The amount of speed that we will apply when input is received
    const float inputAmount = 450.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if ((GetEntity()->GetPos()).x > 190) {
            displacement.x -= inputAmount * dt;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if ((GetEntity()->GetPos()).x < 1700) {
            displacement.x += inputAmount * dt;
        }
    }

    //Update the entity position
    GetEntity()->SetPos(GetEntity()->GetPos() + displacement);
}

void HandPlayerMovementComponent::OnAddToWorld() {}