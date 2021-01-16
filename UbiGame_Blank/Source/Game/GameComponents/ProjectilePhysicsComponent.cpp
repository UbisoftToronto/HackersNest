#include "ProjectilePhysicsComponent.h"
#include <iostream>
#include <GameEngine/GameEngineMain.h>

using namespace Game;

ProjectilePhysicsComponent::ProjectilePhysicsComponent() : velocity(sf::Vector2f(0.f, 0.f))
{

}

ProjectilePhysicsComponent::~ProjectilePhysicsComponent()
{

}

void ProjectilePhysicsComponent::Update()
{
	__super::Update();

	const float dt = GameEngine::GameEngineMain::GetTimeDelta();
	sf::Vector2f displacement{ 0.0f, 0.0f };
	const float speedAmount = 300.0f;

	displacement.x += directionVector.x * speedAmount * dt;
	displacement.y += directionVector.y * speedAmount * dt;

	GetEntity()->SetPos(GetEntity()->GetPos() + displacement);

	updateProjectileHit();
}

void ProjectilePhysicsComponent::updateProjectileHit() 
{
	GameEngine::CollidablePhysicsComponent* colPhys = GetEntity()->GetComponent<GameEngine::CollidablePhysicsComponent>();
	if (!colPhys)
	{
		return;
	}

	if (colPhys->didCollide() && colPhys->getCollidedEntity() != nullptr && static_cast<Game::Bullet*>(GetEntity())->getOwner() != colPhys->getCollidedEntity())
	{
		//Remove self
		GameEngine::GameEngineMain::GetInstance()->RemoveEntity(GetEntity());
		//Remove hit entity
		GameEngine::GameEngineMain::GetInstance()->RemoveEntity(colPhys->getCollidedEntity());
	}
}

void Game::ProjectilePhysicsComponent::setDirectionVector(sf::Vector2f vector)
{
	directionVector = vector;
}
