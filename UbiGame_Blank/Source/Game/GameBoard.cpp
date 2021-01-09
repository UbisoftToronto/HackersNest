#include "GameBoard.h"
#include "Game/Components/PlayerMovementComponent.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"


using namespace Game;

GameBoard::GameBoard()
{
	CreatePlayer();
	CreateBackground();
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

	m_player->SetPos(sf::Vector2f(50.0f, 50.0f));
	m_player->SetSize(sf::Vector2f(50.0f, 50.0f));

	//Render
	GameEngine::SpriteRenderComponent* render = m_player->AddComponent<GameEngine::SpriteRenderComponent>(); //<-- Use the SpriteRenderComponent

	render->SetFillColor(sf::Color::Transparent);
	render->SetTexture(GameEngine::eTexture::Garbage);  // <-- Assign the texture to this entity

	//Movement
	m_player->AddComponent<Game::PlayerMovementComponent>();

}

void GameBoard::CreateBackground() 
{
	background = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(background);

	background->SetPos(sf::Vector2f(250.f, 250.f));
	background->SetSize(sf::Vector2f(800.f, 600.f));

	GameEngine::SpriteRenderComponent* render = static_cast<GameEngine::SpriteRenderComponent*>
									(background->AddComponent<GameEngine::SpriteRenderComponent>());
	render->SetTexture(GameEngine::eTexture::Menu_bg);
	render->SetFillColor(sf::Color::Transparent);
	render->SetZLevel(-1);
}

void GameBoard::TransitionPage() 
{
	cleanTheBox = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(cleanTheBox);

}

void GameBoard::CleanTheBox()
{
	cleanTheBox = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(cleanTheBox);
}

void GameBoard::SortGarbage()
{
	sortGarbage = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(sortGarbage);


}



void GameBoard::Wfh()
{
	wfh = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(wfh);
}

void GameBoard::BakingBread()
{
	bakingBread = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(bakingBread);
}
void GameBoard::WashHands()
{
	washHands = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(washHands);
}

void GameBoard::PutOnMask()
{
	putOnMask = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(putOnMask);
}