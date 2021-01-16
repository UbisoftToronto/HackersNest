#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/Grid.h"
#include "Game/Ball/BallEntity.h"
#include "Game/Paddle/PaddleEntity.h"


using namespace Game;

GameBoard::GameBoard()
	: left_paddle(nullptr), right_paddle(nullptr), ball(nullptr), scoreboard(nullptr), Border(nullptr)
{
	CreatePaddle();
	CreateBall();
	CreateScoreboard();
	Border = new GameEngine::Grid();

}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}


void GameBoard::CreatePaddle() {
	left_paddle = new PaddleEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(left_paddle);
	right_paddle = new Game::PaddleEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(right_paddle);

	left_paddle->SetPos(sf::Vector2f(10.f, 10.f));
	left_paddle->SetSize(sf::Vector2f(50.f, 10.f));
	

	right_paddle->SetPos(sf::Vector2f(100.f, 100.f));
	right_paddle->SetSize(sf::Vector2f(50.f, 10.f));


	//Creates the object in the program
	GameEngine::RenderComponent* render_left = static_cast<GameEngine::RenderComponent*>(left_paddle->AddComponent<GameEngine::RenderComponent>());
	GameEngine::RenderComponent* render_right = static_cast<GameEngine::RenderComponent*>(right_paddle->AddComponent<GameEngine::RenderComponent>());

	//set color
	render_left->SetFillColor(sf::Color::Red);
	render_right->SetFillColor(sf::Color::Blue); 

}

void GameBoard::CreateBall() {
	ball = new BallEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(ball);

	ball->SetPos(sf::Vector2f(100.f, 100.f));
	ball->SetSize(sf::Vector2f(20.f, 20.f));
}



void GameBoard::CreateScoreboard() {
	scoreboard = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(scoreboard);

	scoreboard->SetPos(sf::Vector2f(10.f, 10.f));
	scoreboard->SetSize(sf::Vector2f(10.f, 10.f));
}
