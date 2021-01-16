#include "Bullet.h"
#include "GameEngine/EntitySystem/Components/RenderComponent.h"
#include "Game/GameComponents/ProjectileMovementComponent.h"

Game::Bullet::Bullet()
{
    AddComponent<GameEngine::RenderComponent>();
    AddComponent<Game::ProjectileMovementComponent>();
    SetPos(sf::Vector2f(100.0f, 100.0f));
    SetSize(sf::Vector2f(10.0f, 10.0f));
}

void Game::Bullet::OnAddToWorld()
{

}

void Game::Bullet::OnRemoveFromWorld()
{

}

void Game::Bullet::Update()
{
	Entity::Update();
}