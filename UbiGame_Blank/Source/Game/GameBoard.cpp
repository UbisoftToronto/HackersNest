#include "GameBoard.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/Grid.h"
#include "Game/Scoreboard/Entities/ScoreboardEntity.h"
#include "Game/Ball/BallEntity.h"
#include "Game/Paddle/PaddleEntity.h"
#include "Game/Paddle/PaddleEntity2.h"
#include "GameEngine/EntitySystem/Entity.h"

using namespace Game;
float s = 0;
GameBoard::GameBoard()
	: left_paddle(nullptr), right_paddle(nullptr), ball(nullptr), scoreboard(nullptr), Border(nullptr)
{
	CreatePaddle();
	CreateBall();
	CreateScoreboard();
	Border = new Game::Grid();
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	if (scoreboard->GetSecondsRemaining() > 0) {
		Border->UpdatePixel(ball->GetPos().x, ball->GetPos().y, 0, scoreboard);
	}
}


void GameBoard::CreatePaddle() {
	left_paddle = new PaddleEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(left_paddle);
	right_paddle = new PaddleEntity2();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(right_paddle);

	left_paddle->flag = 2;
	right_paddle->flag =  3;
	

	left_paddle->SetPos(sf::Vector2f(50.f, 100.f));
	left_paddle->SetSize(sf::Vector2f(10.f, 50.f));
	
	float h = GameEngine::GameEngineMain::GetPixelHeight(100.f);
	right_paddle->SetPos(sf::Vector2f(h - 50.f, 100.f));
	right_paddle->SetSize(sf::Vector2f(10.f, 50.f));


	//Creates the object in the program
	GameEngine::RenderComponent* render_left = static_cast<GameEngine::RenderComponent*>(left_paddle->AddComponent<GameEngine::RenderComponent>());
	GameEngine::RenderComponent* render_right = static_cast<GameEngine::RenderComponent*>(right_paddle->AddComponent<GameEngine::RenderComponent>());

	//set color
	render_left->SetFillColor(sf::Color::Red);
	render_right->SetFillColor(sf::Color::Blue);

	//SetZ
	render_left->SetZLevel(2);
	render_right->SetZLevel(2);
	

}

void GameBoard::CreateBall() {
	ball = new BallEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(ball);

	ball->SetPos(sf::Vector2f(100.f, 100.f));
	ball->SetSize(sf::Vector2f(20.f, 20.f));
}

void GameBoard::CreateScoreboard() {
	scoreboard = new ScoreboardEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(scoreboard);

	scoreboard->SetPos(sf::Vector2f(GameEngine::GameEngineMain::GetPixelWidth(50.f), GameEngine::GameEngineMain::GetPixelHeight(95.f)));
	scoreboard->SetSize(sf::Vector2f(GameEngine::GameEngineMain::GetPixelWidth(100.f), GameEngine::GameEngineMain::GetPixelHeight(10.f)));

	scoreboard->InitScoreboard();
}
