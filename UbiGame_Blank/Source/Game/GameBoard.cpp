#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "../PlayerMovementComponent.h"


using namespace Game;

GameBoard::GameBoard()
{
	CreatePlayer();
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}

void GameBoard::CreatePlayer()
{
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);
	
	m_player->SetPos(sf::Vector2f(150.0f, 150.0f));  // <-- Move its initial position
	m_player->SetSize(sf::Vector2f(50.0f, 50.0f)); // <-- Make the square bigger

	GameEngine::RenderComponent* render = m_player->AddComponent<GameEngine::RenderComponent>(); // <-- Capturing the new component

	render->SetFillColor(sf::Color::Red); // <-- Change the fill color to Red
	m_player->AddComponent<Game::PlayerMovementComponent>();  // <-- Added the movement component to the player
}