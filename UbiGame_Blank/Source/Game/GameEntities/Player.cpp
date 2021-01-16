#include "Player.h"
#include "GameEngine/EntitySystem/Components/RenderComponent.h"
#include <Game/GameComponents/PlayerActionComponent.h>

Game::Player::Player() : playerHealth(100)
{
	SetPos(sf::Vector2f(50.0f, 50.0f));
	SetSize(sf::Vector2f(50.0f, 50.0f));

	AddComponent<GameEngine::RenderComponent>();
	AddComponent<Game::PlayerActionComponent>();
	movementComponent = AddComponent<Game::PlayerMovementComponent>();
}

void Game::Player::setControls(int controls[4]) 
{
	movementComponent->setPlayerControls(controls);
}

void Game::Player::OnAddToWorld() 
{
	
}

void Game::Player::OnRemoveFromWorld()
{

}

void Game::Player::Update()
{
	Entity::Update();
}