#include "PlayerActionComponent.h"
#include <SFML/Window/Keyboard.hpp>
#include "GameEngine/GameEngineMain.h"

void Game::PlayerActionComponent::Update()
{
	Component::Update();

	if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(sf::Keyboard::Space))) {
		bullet = new Game::Bullet();
		bullet->SetPos(GetEntity()->GetPos());
		GameEngine::GameEngineMain::GetInstance()->AddEntity(bullet);
		
	}
}

void Game::PlayerActionComponent::OnAddToWorld() 
{
	
}

void Game::PlayerActionComponent::setPlayerAction(int action) 
{
	this->playerAction = action;
}