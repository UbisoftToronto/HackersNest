#include "PlayerMovementComponent.h"
#include <SFML/Window/Keyboard.hpp>
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/GravityPhysicsComponent.h"

using namespace Game;

void PlayerMovementComponent::Update() 
{
    Component::Update();
    float playerVelocity = 100.f;
    float jumpVelocity = 50.f;
    bool m_wasJumpButtonPressed = false;

    sf::Vector2f wantedVelocity = sf::Vector2f(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if (!m_wasJumpButtonPressed && wantedVelocity.y >= 0)
        {
            wantedVelocity.y -= jumpVelocity;
            m_wasJumpButtonPressed = true;
        }
    }
    else
    {
        wantedVelocity.y = 0;
        m_wasJumpButtonPressed = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        wantedVelocity.x -= playerVelocity;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        wantedVelocity.y += playerVelocity;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        wantedVelocity.x += playerVelocity;
    }

    GameEngine::GravityPhysicsComponent* gravPhys = GetEntity()->GetComponent<GameEngine::GravityPhysicsComponent>();
    if (gravPhys)
    {
        gravPhys->SetVelocity(wantedVelocity);
    }
}

void PlayerMovementComponent::OnAddToWorld() {}
