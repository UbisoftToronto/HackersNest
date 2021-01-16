#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"




using namespace Game;

GameBoard::GameBoard()
	: left_paddle(nullptr), right_paddle(nullptr), ball(nullptr), scoreboard(nullptr)
{
	CreatePaddle();
	CreateBall();
	CreateScoreboard();
	

}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}


void GameBoard::CreatePaddle() {
	left_paddle = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(left_paddle);
	right_paddle = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(right_paddle);

	left_paddle->SetPos(sf::Vector2f(10.f, 10.f));
	left_paddle->SetSize(sf::Vector2f(10.f, 10.f));

	right_paddle->SetPos(sf::Vector2f(10.f, 10.f));
	right_paddle->SetSize(sf::Vector2f(10.f, 10.f));
}

void GameBoard::CreateBall() {
	ball = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(ball);

	ball->SetPos(sf::Vector2f(10.f, 10.f));
	ball->SetSize(sf::Vector2f(10.f, 10.f));
}



void GameBoard::CreateScoreboard() {
	scoreboard = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(scoreboard);

	scoreboard->SetPos(sf::Vector2f(10.f, 10.f));
	scoreboard->SetSize(sf::Vector2f(10.f, 10.f));
}
