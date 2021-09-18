#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"
#include "Game/GameEntities/PlayerEntity.h"

using namespace Game;

GameBoard::GameBoard()
  : m_player(nullptr)
{
	CreatePlayer();
  CreateBackground();

}

void GameBoard::CreatePlayer()
{
  m_player = new PlayerEntity();
	
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);
	m_player->SetPos(sf::Vector2f(60.f, 60.f));	
	m_player->SetSize(sf::Vector2f(60.f, 60.f));
}

void GameBoard::CreateBackground()
{
	GameEngine::Entity* bgEntity = new GameEngine::Entity();
	GameEngine::SpriteRenderComponent* render = bgEntity->AddComponent<GameEngine::SpriteRenderComponent>();
	render->SetTexture(GameEngine::eTexture::BG);
	render->SetZLevel(0);
	bgEntity->SetPos(sf::Vector2f(250.f, 250.f));
	bgEntity->SetSize(sf::Vector2f(500.f, 500.f));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(bgEntity);

	m_backGround = bgEntity;
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{		
}


