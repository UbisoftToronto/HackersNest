#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "Game/GameComponents/PlayerMovementComponent.h"


using namespace Game;

GameBoard::GameBoard() : player1(nullptr), player2(nullptr)
{
    player1 = new GameEngine::Entity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(player1);
    player2 = new GameEngine::Entity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(player2);

    player1->SetPos(sf::Vector2f(50.0f, 50.0f));
    player1->SetSize(sf::Vector2f(50.0f, 50.0f));
    player2->SetPos(sf::Vector2f(200.0f, 200.0f));
    player2->SetSize(sf::Vector2f(50.0f, 50.0f));

    //Render
    GameEngine::RenderComponent* render1 = player1->AddComponent<GameEngine::RenderComponent>();
    GameEngine::RenderComponent* render2 = player2->AddComponent<GameEngine::RenderComponent>();

    //Movement
    int player1Controls[4] = {sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::W, sf::Keyboard::S};
    int player2Controls[4] = {sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Up, sf::Keyboard::Down};
    player1->AddComponent<Game::PlayerMovementComponent>();
    player1->GetComponent<Game::PlayerMovementComponent>()->setPlayerControls(player1Controls);
    player2->AddComponent<Game::PlayerMovementComponent>();
    player2->GetComponent<Game::PlayerMovementComponent>()->setPlayerControls(player2Controls);
}


GameBoard::~GameBoard()
{

}

void GameBoard::Update()
{	
	
}

void GameBoard::setGameStarted(bool newState) {
    gameStarted = newState;
}

bool GameBoard::getGameStarted() {
    return gameStarted;
}

void GameBoard::buildStartScreen(){

}