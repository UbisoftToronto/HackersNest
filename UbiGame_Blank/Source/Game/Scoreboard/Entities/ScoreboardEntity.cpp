#include "ScoreboardEntity.h"
#include "GameEngine/GameEngineMain.h"
#include "ScoreEntity.h"
#include "TimerEntity.h"

using namespace Game;

ScoreboardEntity::ScoreboardEntity()
	: timer(nullptr)
{
	// Render
	m_renderComponent = AddComponent<GameEngine::RenderComponent>();
	m_renderComponent->SetFillColor(sf::Color::White);
	m_renderComponent->SetZLevel(1);
}


ScoreboardEntity::~ScoreboardEntity()
{

}


void ScoreboardEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();
}


void ScoreboardEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();
}

void ScoreboardEntity::InitScoreboard()
{
	// Render Text
	float xScoreboard = GetPos().x;
	float yScoreboard = GetPos().y;
	float widthScoreboard = GetSize().x;
	float heightScoreboard = GetSize().y;

	ScoreEntity* scoreP1 = new ScoreEntity(0);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(scoreP1);
	scoreP1->SetPos(sf::Vector2f(xScoreboard - widthScoreboard * 0.35f - GameEngine::GameEngineMain::GetPixelWidth(5.f), yScoreboard - GameEngine::GameEngineMain::GetPixelHeight(2.f)));
	scores.push_back(scoreP1);

	ScoreEntity* scoreP2 = new ScoreEntity(0);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(scoreP2);
	scoreP2->SetPos(sf::Vector2f(xScoreboard + widthScoreboard * 0.35f - GameEngine::GameEngineMain::GetPixelWidth(5.f), yScoreboard - GameEngine::GameEngineMain::GetPixelHeight(2.f)));
	scores.push_back(scoreP2);

	timer = new TimerEntity(60);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(timer);
	timer->SetPos(sf::Vector2f(xScoreboard - GameEngine::GameEngineMain::GetPixelWidth(2.f), yScoreboard - GameEngine::GameEngineMain::GetPixelHeight(2.f)));
}

void ScoreboardEntity::UpdateScore(int playerNumber, int score)
{
	scores[playerNumber]->UpdateScore(score);
}