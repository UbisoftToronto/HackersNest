#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "Game/GameComponents/PlayerMovementComponent.h"

using namespace Game;

GameBoard::GameBoard() : player1(nullptr), player2(nullptr), bullet(nullptr)
{
    int player1Controls[4] = { sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::W, sf::Keyboard::S };
    int player2Controls[4] = { sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Up, sf::Keyboard::Down };

    player1 = new Game::Player();
    player1->setControls(player1Controls);
    GameEngine::GameEngineMain::GetInstance()->AddEntity(player1);

    player2 = new Game::Player();
    player2->setControls(player2Controls);
    GameEngine::GameEngineMain::GetInstance()->AddEntity(player2);

    bullet = new Game::Bullet();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(bullet);
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}