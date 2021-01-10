#include "GameBoard.h"
#include "Game/Components/PlayerMovementComponent.h"
#include "Game/Components/SortGarbageComponent.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include <string>
#include <iostream>


using namespace Game;

GameBoard::GameBoard(){
	//CreatePlayer();
	SortGarbage();
	CreateBackground(GameEngine::eTexture::SortGarbage_bg);
	std::cout << "hello";
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
	GameEngine::SpriteRenderComponent *render = m_player->AddComponent<GameEngine::SpriteRenderComponent>(); //<-- Use the SpriteRenderComponent

	render->SetFillColor(sf::Color::White);
	render->SetTexture(GameEngine::eTexture::Garbage); // <-- Assign the texture to this entity

	//Movement
	m_player->AddComponent<Game::PlayerMovementComponent>();
}

void GameBoard::CreateBackground(GameEngine::eTexture::type texture)
{
	background = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(background);

	background->SetPos(sf::Vector2f(940.f, 540.f));
	background->SetSize(sf::Vector2f(1920.f, 1080.f));

	GameEngine::SpriteRenderComponent *render = static_cast<GameEngine::SpriteRenderComponent *>(background->AddComponent<GameEngine::SpriteRenderComponent>());

	background->AddComponent<Game::SortGarbageComponent>();

	render->SetTexture(texture);
	render->SetFillColor(sf::Color::White);
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

	GameEngine::Entity* garbage = CreateImage(GameEngine::eTexture::type::Garbage, 1375.0f, 550.0f, 175.0f, 175.0f);
	GameEngine::Entity* compost = CreateImage(GameEngine::eTexture::type::Compost, 1400.0f, 720.0f, 175.0f, 175.0f);
	GameEngine::Entity* recycling = CreateImage(GameEngine::eTexture::type::Recycling, 1400.0f, 900.0f, 175.0f, 175.0f);

	GameEngine::Entity* alCan = CreateImage(GameEngine::eTexture::type::AluminumCan, 650.0f, 600.0f, 150.0f, 150.0f);
	GameEngine::Entity* banana = CreateImage(GameEngine::eTexture::type::BananaPeel, 600.0f, 750.0f, 170.0f, 150.0f);
	GameEngine::Entity* bottle = CreateImage(GameEngine::eTexture::type::Bottle, 850.0f, 850.0f, 90.0f, 170.0f);
	GameEngine::Entity* chips = CreateImage(GameEngine::eTexture::type::ChipBag, 450.0f, 650.0f, 130.0f, 150.0f);
	GameEngine::Entity* fish = CreateImage(GameEngine::eTexture::type::Fish, 800.0f, 720.0f, 170.0f, 80.0f);
	GameEngine::Entity* garbageBall = CreateImage(GameEngine::eTexture::type::GarbageBall, 470.0f, 900.0f, 130.0f, 150.0f);

}

GameEngine::Entity* GameBoard::CreateImage(GameEngine::eTexture::type texture, float x, float y, float size_x, float size_y)
{
	GameEngine::Entity* image = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(image);

	image->SetPos(sf::Vector2f(x, y));
	image->SetSize(sf::Vector2f(size_x, size_y));

	//Render
	GameEngine::SpriteRenderComponent *render = image->AddComponent<GameEngine::SpriteRenderComponent>(); //<-- Use the SpriteRenderComponent

	render->SetFillColor(sf::Color::Transparent);
	render->SetTexture(texture);  // <-- Assign the texture to this entity

	return image;
}

void GameBoard::Wfh()
{
	wfh = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(wfh);
	CreateBackground(GameEngine::eTexture::WFH_bg);
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