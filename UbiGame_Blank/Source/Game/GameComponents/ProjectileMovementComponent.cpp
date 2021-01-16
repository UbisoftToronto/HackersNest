#include "ProjectileMovementComponent.h"
#include "GameEngine/GameEngineMain.h"

void Game::ProjectileMovementComponent::Update()
{
	const float dt = GameEngine::GameEngineMain::GetTimeDelta();
	sf::Vector2f displacement{ 0.0f, 0.0f };
	const float speedAmount = 300.0f;

	displacement.x += speedAmount * dt;

	GetEntity()->SetPos(GetEntity()->GetPos() + displacement);
}

void Game::ProjectileMovementComponent::OnAddToWorld()
{

}

void Game::ProjectileMovementComponent::setVelocity(sf::Vector2f velocity)
{
	this->velocity = velocity;
}