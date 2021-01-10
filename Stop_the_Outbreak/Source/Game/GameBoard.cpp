#include "GameBoard.h"
#include "Game/Components/PlayerMovementComponent.h"
#include "Game/Components/HandPlayerMovementComponent.h"
#include "Game/Components/WaterMovementComponent.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include <Game/Components/ImageClickComponent.h>
#include <cstdlib>

#include <iostream>

using namespace Game;

GameBoard::GameBoard()
{
	//CreatePlayer();
	//CreateBackground(GameEngine::eTexture::CleanBox_bg);
	//PutOnMask();
	//WashHands();
	CreateBackground(GameEngine::eTexture::type::WashYoHands_bg);
	CreateHandPlayer();
	CreateWater();
	//UpdateWashHands();
}
 

GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	float dt = GameEngine::GameEngineMain::GetInstance()->GetTimeDelta();
	if (!wh_isGameOver) {
		lastWaterSpawnTimer -= dt;
		if (lastWaterSpawnTimer <= 0.f && waterCount < 7) {
			CreateWater();
		}
		UpdateWaters();
	}
	else 
	{
		GameEngine::SpriteRenderComponent* render = handplayer->AddComponent<GameEngine::SpriteRenderComponent>();
		if (waterCount == 8) {
			render->SetTexture(GameEngine::eTexture::type::ShinyHands);  // <-- Assign the texture to this entity
		}
		else {
			render->SetTexture(GameEngine::eTexture::type::SoapyHands);  // <-- Assign the texture to this entity
		}
	}
}

void GameBoard::CreatePlayer()
{
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);

	m_player->SetPos(sf::Vector2f(50.0f, 50.0f));
	m_player->SetSize(sf::Vector2f(50.0f, 50.0f));

	//Render
	GameEngine::SpriteRenderComponent* render = m_player->AddComponent<GameEngine::SpriteRenderComponent>(); //<-- Use the SpriteRenderComponent

	render->SetFillColor(sf::Color::White);
	render->SetTexture(GameEngine::eTexture::Garbage);  // <-- Assign the texture to this entity

	//Movement
	m_player->AddComponent<Game::PlayerMovementComponent>();

}

void GameBoard::CreateBackground(GameEngine::eTexture::type texture)
{
	background = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(background);

	background->SetPos(sf::Vector2f(940.f, 540.f));
	background->SetSize(sf::Vector2f(1920.f, 1080.f));

	GameEngine::SpriteRenderComponent* render = static_cast<GameEngine::SpriteRenderComponent*>
									(background->AddComponent<GameEngine::SpriteRenderComponent>());
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


}

void GameBoard::CreateImage(GameEngine::eTexture::type texture, float x, float y)
{
	image = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(image);

	image->SetPos(sf::Vector2f(x, y));
	image->SetSize(sf::Vector2f(50.0f, 50.0f));

	//Render
	GameEngine::SpriteRenderComponent* render = image->AddComponent<GameEngine::SpriteRenderComponent>(); //<-- Use the SpriteRenderComponent

	render->SetFillColor(sf::Color::Transparent);
	render->SetTexture(GameEngine::eTexture::Garbage);  // <-- Assign the texture to this entity

	//Click status
	//image->AddComponent<Game::ImageClickComponent>();

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


////////////////////////////////// Wash Hand game //////////////////////////////////

void GameBoard::CreateHandPlayer()
{
	handplayer = new GameEngine::Entity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(handplayer);

    handplayer->SetPos(sf::Vector2f(1000.0f, 955.0f));
    handplayer->SetSize(sf::Vector2f(425.0f, 250.0f));

    //Render
    GameEngine::SpriteRenderComponent* render = handplayer->AddComponent<GameEngine::SpriteRenderComponent>(); //<-- Use the SpriteRenderComponent

    render->SetTexture(GameEngine::eTexture::type::Hands);  // <-- Assign the texture to this entity
    render->SetFillColor(sf::Color::White);

    //Movement 
    handplayer->AddComponent<Game::HandPlayerMovementComponent>();
}

void GameBoard::CreateWater()
{
	waterCount++;
	water = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(water);

    water->SetPos(sf::Vector2f(RandomFloatRange(240.0,1700.0), 90.0f));
    water->SetSize(sf::Vector2f(360.0f, 180.0f));

	//Render
    GameEngine::SpriteRenderComponent* render = water->AddComponent<GameEngine::SpriteRenderComponent>(); //<-- Use the SpriteRenderComponent

    render->SetTexture(GameEngine::eTexture::type::Water);  // <-- Assign the texture to this entity
    render->SetFillColor(sf::Color::Transparent);

    //Movement
    water->AddComponent<Game::WaterMovementComponent>();

	lastWaterSpawnTimer = 1.f;
	waters.push_back(water);
}

void GameBoard::UpdateWaters()
{
	for (std::vector<GameEngine::Entity*>::iterator it = waters.begin(); it != waters.end();)
	{
		GameEngine::Entity* this_water = (*it);
		sf::Vector2f currPosW = this_water->GetPos();
		sf::Vector2f currPosH = handplayer->GetPos();
		if (abs(currPosW.x - currPosH.x) < 15 && abs(currPosW.y - currPosH.y) < 15)
		{
			GameEngine::GameEngineMain::GetInstance()->RemoveEntity(this_water);
			it = waters.erase(it);
			if (waterCount == 8) {
				wh_isGameOver == true;
			}
		}
		else if (currPosW.y >= 955)
		{
			GameEngine::GameEngineMain::GetInstance()->RemoveEntity(this_water);
			it = waters.erase(it);
			wh_isGameOver == true;
		}
		else
		{
			it++;
		}
	}
}

void GameBoard::WashHands()
{
	CreateBackground(GameEngine::eTexture::type::WashYoHands_bg);
	CreateHandPlayer();
	CreateWater();
	UpdateWashHands();
}

void GameBoard::UpdateWashHands()
{
	float dt = GameEngine::GameEngineMain::GetInstance()->GetTimeDelta();
	if (!wh_isGameOver) {
		lastWaterSpawnTimer -= dt;
		if (lastWaterSpawnTimer <= 0.f && waterCount < 7) {
			CreateWater();
		}
		UpdateWaters();
	}
	else 
	{
		GameEngine::SpriteRenderComponent* render = handplayer->AddComponent<GameEngine::SpriteRenderComponent>();
		if (waterCount == 8) {
			render->SetTexture(GameEngine::eTexture::type::ShinyHands);  // <-- Assign the texture to this entity
		}
		else {
			render->SetTexture(GameEngine::eTexture::type::SoapyHands);  // <-- Assign the texture to this entity
		}
	}
}

////////////////////////////////// Mask game //////////////////////////////////

void GameBoard::CreateMaskPlayer()
{
    maskplayer = new GameEngine::Entity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(maskplayer);

    maskplayer->SetPos(sf::Vector2f(1000.0f, 955.0f));
    maskplayer->SetSize(sf::Vector2f(250.0f, 250.0f));

    //Render
    GameEngine::SpriteRenderComponent* render = maskplayer->AddComponent<GameEngine::SpriteRenderComponent>(); //<-- Use the SpriteRenderComponent

    render->SetTexture(GameEngine::eTexture::type::Face);  // <-- Assign the texture to this entity
    render->SetFillColor(sf::Color::White);

    //Movement
    maskplayer->AddComponent<Game::HandPlayerMovementComponent>();
}

void GameBoard::CreateMask()
{
	mask = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(mask);

	float rand_x = 250.0 + (static_cast <float> (rand()) / static_cast <float> (RAND_MAX/(800.0 - 120.0)));
	
    mask->SetPos(sf::Vector2f(rand_x, 90.0f));
    mask->SetSize(sf::Vector2f(240.0f, 120.0f));

	//Render
    GameEngine::SpriteRenderComponent* render = mask->AddComponent<GameEngine::SpriteRenderComponent>(); //<-- Use the SpriteRenderComponent

    render->SetTexture(GameEngine::eTexture::type::Mask);  // <-- Assign the texture to this entity
    render->SetFillColor(sf::Color::Transparent);

    //Movement
    mask->AddComponent<Game::WaterMovementComponent>();
}

void GameBoard::PutOnMask()
{
    CreateMaskPlayer();
	CreateMask();
    CreateBackground(GameEngine::eTexture::type::PutOnMask_bg);
}