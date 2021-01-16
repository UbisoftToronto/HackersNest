#include "PlayerMovementComponent.h"
#include <SFML/Window/Keyboard.hpp>
#include "GameEngine/GameEngineMain.h"

using namespace Game;

void PlayerMovementComponent::setPlayerControls(int playerControls[6]) 
{
    controls[0] = playerControls[0];
    controls[1] = playerControls[1];
    controls[2] = playerControls[2];
    controls[3] = playerControls[3];
    controls[4] = playerControls[4];
    controls[5] = playerControls[5];
}

void PlayerMovementComponent::Update()
{
    Component::Update();

    const float dt = GameEngine::GameEngineMain::GetTimeDelta();

    sf::Vector2f displacement{0.0f, 0.0f};
    const float speedAmount = 250.0f;

    if(sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(controls[0])))
    {
        displacement.x -= speedAmount * dt;
    }
    if(sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(controls[1])))
    {
        displacement.x += speedAmount * dt;
    }

    if(sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(controls[2])))
    {
        displacement.y -= speedAmount * dt;
    }
    if(sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(controls[3])))
    {
        displacement.y += speedAmount * dt;
    }

    GetEntity()->SetPos(GetEntity()->GetPos() + displacement);


    float rotation = 0;
    const float turnSpeed = 65.f;
    if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(controls[4])))
    {
        rotation += -turnSpeed * dt;
    }
    if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(controls[5])))
    {
        rotation += turnSpeed * dt;
    }

    GetEntity()->SetRotation(GetEntity()->GetRot() + rotation);
}

void PlayerMovementComponent::OnAddToWorld()
{
    Component::OnAddToWorld();
}


