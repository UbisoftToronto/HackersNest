#include "Bullet.h"
#include "GameEngine/EntitySystem/Components/RenderComponent.h"
#include <GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h>
#include <Game/GameComponents/ProjectilePhysicsComponent.h>

Game::Bullet::Bullet()
{
    setEntityType(GameEngine::EntityType::BULLET);
    AddComponent<GameEngine::RenderComponent>();
    projectilePhysicsComponent = AddComponent<Game::ProjectilePhysicsComponent>();

    SetSize(sf::Vector2f(10.0f, 10.0f));
}

void Game::Bullet::OnAddToWorld()
{
    Entity::OnAddToWorld();
}

void Game::Bullet::OnRemoveFromWorld()
{
    Entity::OnRemoveFromWorld();
}

void Game::Bullet::Update()
{
	Entity::Update();
}

void Game::Bullet::setDirectionVector(sf::Vector2f vector)
{
    projectilePhysicsComponent->setDirectionVector(vector);
}

void Game::Bullet::setOwner(GameEngine::Entity* entity)
{
    owner = entity;
}

GameEngine::Entity* Game::Bullet::getOwner()
{
    return owner;
}
