#include "Player.h"
#include "GameEngine/EntitySystem/Components/RenderComponent.h"
#include <Game/GameComponents/PlayerActionComponent.h>
#include <GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h>

Game::Player::Player() : playerHealth(100)
{
	setEntityType(GameEngine::EntityType::PLAYER);
	SetPos(sf::Vector2f(50.0f, 50.0f));
	SetSize(sf::Vector2f(50.0f, 50.0f));

	AddComponent<GameEngine::RenderComponent>();
	AddComponent<GameEngine::CollidablePhysicsComponent>();
	actionComponent = AddComponent<Game::PlayerActionComponent>();
	movementComponent = AddComponent<Game::PlayerMovementComponent>();
}

void Game::Player::setControls(int controls[4]) 
{
	movementComponent->setPlayerControls(controls);
}

void Game::Player::setActionButton(int actionButton)
{
	actionComponent->setPlayerAction(actionButton);
}

void Game::Player::OnAddToWorld() 
{
	Entity::OnAddToWorld();
}

void Game::Player::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();
}

void Game::Player::Update()
{
	Entity::Update();
}