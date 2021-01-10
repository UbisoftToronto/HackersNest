#include "GameBoard.h"
#include "Game/Components/PlayerMovementComponent.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
<<<<<<< HEAD
#include <string>
#include <iostream>

#include<Windows.h>
#include<Winuser.h >

=======
#include <Game/Components/ImageClickComponent.h>
>>>>>>> c93ed8329b21c00fa7346af2b055690ee05d6d7c

using namespace Game;

GameBoard::GameBoard()
{
<<<<<<< HEAD
	//CreatePlayer();
	Game::GameBoard::lives = 3;
	SortGarbage();
	CreateBackground(GameEngine::eTexture::Menu_bg);
	std::cout << "hello";
=======
	CreatePlayer();
	CreateBackground(GameEngine::eTexture::Menu_bg);
	Wfh();
>>>>>>> c93ed8329b21c00fa7346af2b055690ee05d6d7c
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

<<<<<<< HEAD
	GameEngine::SpriteRenderComponent* render = static_cast<GameEngine::SpriteRenderComponent*>
									(background->AddComponent<GameEngine::SpriteRenderComponent>());
=======
	GameEngine::SpriteRenderComponent *render = static_cast<GameEngine::SpriteRenderComponent *>(background->AddComponent<GameEngine::SpriteRenderComponent>());
>>>>>>> c93ed8329b21c00fa7346af2b055690ee05d6d7c
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
<<<<<<< HEAD

	GameEngine::Entity* garbage = CreateImage(GameEngine::eTexture::type::Garbage, 400.0f, 250.0f, 100.0f, 100.0f);
	GameEngine::Entity* compost = CreateImage(GameEngine::eTexture::type::Compost, 400.0f, 350.0f, 100.0f, 100.0f);
	GameEngine::Entity* recycling = CreateImage(GameEngine::eTexture::type::Recycling, 400.0f, 450.0f, 100.0f, 100.0f);

	GameEngine::Entity* alCan = CreateImage(GameEngine::eTexture::type::AluminumCan, 185.0f, 240.0f, 75.0f, 75.0f);
	GameEngine::Entity* banana = CreateImage(GameEngine::eTexture::type::BananaPeel, 230.0f, 350.0f, 85.0f, 75.0f);
	GameEngine::Entity* bottle = CreateImage(GameEngine::eTexture::type::Bottle, 195.0f, 450.0f, 45.0f, 85.0f);
	GameEngine::Entity* chips = CreateImage(GameEngine::eTexture::type::ChipBag, 85.0f, 290.0f, 65.0f, 75.0f);
	GameEngine::Entity* fish = CreateImage(GameEngine::eTexture::type::Fish, 120.0f, 375.0f, 85.0f, 40.0f);
	GameEngine::Entity* garbageBall = CreateImage(GameEngine::eTexture::type::GarbageBall, 75.0f, 450.0f, 65.0f, 75.0f);

	//bool fail = false;
	//sf::Event event;
	//while (window.pollEvent(event))
	//{
	//	// check the type of the event...
	//	switch (event.type)
	//	{
	//		// window closed
	//	case sf::Event::Closed:
	//		window.close();
	//		break;

	//		// key pressed
	//	case sf::Event::KeyPressed:
	//		...
	//			break;

	//		// we don't process other types of events
	//	default:
	//		break;
	//	}
	//}

	//if (fail)
	//	--Game::GameBoard::lives;
=======
>>>>>>> c93ed8329b21c00fa7346af2b055690ee05d6d7c
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
<<<<<<< HEAD
	render->SetTexture(texture);  // <-- Assign the texture to this entity

	return image;
=======
	render->SetTexture(GameEngine::eTexture::Garbage); // <-- Assign the texture to this entity

	//Click status
	//image->AddComponent<Game::ImageClickComponent>();
>>>>>>> c93ed8329b21c00fa7346af2b055690ee05d6d7c
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