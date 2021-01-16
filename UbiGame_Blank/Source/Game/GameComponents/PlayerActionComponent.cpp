#include "PlayerActionComponent.h"
#include <SFML/Window/Keyboard.hpp>
#include "GameEngine/GameEngineMain.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace Game;

Game::PlayerActionComponent::PlayerActionComponent() : firePressed(false)
{

}

Game::PlayerActionComponent::~PlayerActionComponent()
{
}

void Game::PlayerActionComponent::Update()
{
	Component::Update();

	if (inputDisabled) return;

	if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(playerActionKey))) {
		firePressed = true;
		
	}
	else
	{
		if (firePressed)
		{
			spawnBullet();
		}
		firePressed = false;
	}
}

void Game::PlayerActionComponent::OnAddToWorld() 
{
	
}

void Game::PlayerActionComponent::setPlayerAction(int action) 
{
	this->playerActionKey = action;
}

void Game::PlayerActionComponent::disableInput(bool disable)
{
	inputDisabled = disable;
}

void PlayerActionComponent::spawnBullet() 
{
	GameEngine::Entity* entity = GetEntity();
	if (entity->getEntityType() == GameEngine::EntityType::PLAYER) 
	{
		Game::Player* player = static_cast<Game::Player*>(GetEntity());
		Game::Bullet* bullet = new Game::Bullet();

		player->addBullet(bullet);
		bullet->setOwner(player);
		bullet->SetPos(player->GetPos());
		
		float rotation = GetEntity()->GetRot();
		sf::Vector2f playerFacingUnitVector = sf::Vector2f(cos(rotation / 180 * M_PI), sin(rotation / 180 * M_PI));
		bullet->setDirectionVector(playerFacingUnitVector);
		GameEngine::GameEngineMain::GetInstance()->AddEntity(bullet);
	}
	
	
}