#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "Components/PlayerMovementComponent.h"
#include "Components/SpriteCameraComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include <SFML/System/Vector2.hpp>

using namespace Game;

GameBoard::GameBoard()
{
    CreatePlayer();
	CreateObstacle();
}

void GameBoard::CreatePlayer()
{
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);

	m_player->SetPos(sf::Vector2f(50.0f, 50.0f));
	m_player->SetSize(sf::Vector2f(10.0f, 40.0f));

	//Render
	GameEngine::RenderComponent* render = m_player->AddComponent<GameEngine::RenderComponent>();

	render->SetFillColor(sf::Color::Red);

	//Movement
	m_player->AddComponent<Game::PlayerMovementComponent>();  // <-- Added the movement component to the player
	//m_player->AddComponent<Game::SpriteCameraComponent>();  // <-- Attach Camera to the player
	m_player->AddComponent<GameEngine::CollidablePhysicsComponent>(); // <-- For colliding with obstacle
}


void GameBoard::CreateObstacle()
{
	GameEngine::Entity* obstacle = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(obstacle);

	obstacle->SetPos(sf::Vector2f(60.f, 60.f));
	obstacle->SetSize(sf::Vector2f(100.f, 100.f));

	//Render
	GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
		(obstacle->AddComponent<GameEngine::SpriteRenderComponent>());

	spriteRender->SetFillColor(sf::Color::Transparent);
	spriteRender->SetTexture(GameEngine::eTexture::Obstacle);

	obstacle->AddComponent<GameEngine::CollidableComponent>();
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}