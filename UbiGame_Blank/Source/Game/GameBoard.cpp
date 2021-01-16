#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "Game/GameComponents/PlayerMovementComponent.h"


using namespace Game;

GameBoard::GameBoard() : player(nullptr)
{
    player = new GameEngine::Entity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(player);

    player->SetPos(sf::Vector2f(50.0f, 50.0f));
    player->SetSize(sf::Vector2f(50.0f, 50.0f));

    //Render
    GameEngine::RenderComponent* render = player->AddComponent<GameEngine::RenderComponent>();
    //Movement
    int controls[4] = {0, 1, 2, 3};
    player->AddComponent<Game::PlayerMovementComponent>();
    player->GetComponent<Game::PlayerMovementComponent>()->setPlayerControls(controls);
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}