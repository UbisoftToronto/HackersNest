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
	// Uncomment the lines here and in Update() for the game you would like to see
	
	// WashHands();

	//PutOnMask();
}
 

GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
	UpdateWashHands();

	//UpdatePutOnMask();
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

////////////////////////////////// Garbage sort game //////////////////////////////////

void GameBoard::SortGarbage()
{

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

////////////////////////////////// Work from Home //////////////////////////////////

void GameBoard::Wfh()
{
	wfh = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(wfh);
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
		if (abs(currPosW.x - currPosH.x) < 200 && abs(currPosW.y - currPosH.y) < 100)
		{
			GameEngine::GameEngineMain::GetInstance()->RemoveEntity(this_water);
			it = waters.erase(it);
			caughtWaterCount++;
			if (waterCount == 10) {
				wh_isGameOver = true;
			}
		}
		else if (currPosW.y >= 955)
		{
			GameEngine::GameEngineMain::GetInstance()->RemoveEntity(this_water);
			it = waters.erase(it);
			if (waterCount == 10) {
				wh_isGameOver = true;
			}
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
}

void GameBoard::UpdateWashHands()
{
	float dt = GameEngine::GameEngineMain::GetInstance()->GetTimeDelta();
	if (!wh_isGameOver) {
		lastWaterSpawnTimer -= dt;
		if (lastWaterSpawnTimer <= 0.f && waterCount < 10) {
			CreateWater();
		}
		UpdateWaters();
	}
	else 
	{
		GameEngine::SpriteRenderComponent* render = handplayer->GetComponent<GameEngine::SpriteRenderComponent>();
		if (waterCount == caughtWaterCount) {
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

    maskplayer->SetPos(sf::Vector2f(950.0f, 600.0f));
    maskplayer->SetSize(sf::Vector2f(300.0f, 300.0f));

    //Render
    GameEngine::SpriteRenderComponent* render = maskplayer->AddComponent<GameEngine::SpriteRenderComponent>();
    render->SetTexture(GameEngine::eTexture::type::Face); 
    render->SetFillColor(sf::Color::White);
}

void GameBoard::CreateMask()
{
	mask = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(mask);
	
    mask->SetPos(sf::Vector2f(RandomFloatRange(300.0,1700.0), RandomFloatRange(240.0,800.0)));
    mask->SetSize(sf::Vector2f(300.0f, 150.0f));

	//Render
    GameEngine::SpriteRenderComponent* render = mask->AddComponent<GameEngine::SpriteRenderComponent>(); 
    render->SetTexture(GameEngine::eTexture::type::Mask); 
    render->SetFillColor(sf::Color::Transparent);

	lastMaskSpawnTime = 1.f;
}

void GameBoard::UpdateMask()
{
	mask->SetPos(sf::Vector2f(RandomFloatRange(300.0,1700.0), RandomFloatRange(240.0,800.0)));
	lastMaskSpawnTime = 1.f;
	maskCount++;
}

void GameBoard::PutOnMask()
{
    
	CreateBackground(GameEngine::eTexture::type::PutOnMask_bg);
	CreateMaskPlayer();
	CreateMask();
}

void GameBoard::UpdatePutOnMask()
{
float dt = GameEngine::GameEngineMain::GetInstance()->GetTimeDelta();
	if (!m_isGameOver) {
		lastMaskSpawnTime -= dt;
		sf::Vector2f currPosM = mask->GetPos();
		sf::Vector2f currPosF = maskplayer->GetPos();
		if (abs(currPosM.x - currPosF.x) < 30 && abs(currPosM.y - currPosF.y) < 30) {
			// if (mouseclick) {
			// 	m_isGameOver = true;
			//  maskWin = true;
			// }
		}
		else if (lastMaskSpawnTime <= 0.f && maskCount < 15) {
			UpdateMask();
		}
		
	}
	else 
	{
		GameEngine::SpriteRenderComponent* render = maskplayer->GetComponent<GameEngine::SpriteRenderComponent>();
		if (maskWin) {
			render->SetTexture(GameEngine::eTexture::type::Face); 
		}
		else {
			render->SetTexture(GameEngine::eTexture::type::Face); 
		}
	}
}