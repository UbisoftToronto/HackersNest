#include "ScoreEntity.h"
#include "GameEngine/GameEngineMain.h"

using namespace Game;

ScoreEntity::ScoreEntity(std::string score)
{
	// Render
	m_scoreTextRenderComponent = AddComponent<GameEngine::TextRenderComponent>();
	m_scoreTextRenderComponent->SetFont("arial.ttf");
	m_scoreTextRenderComponent->SetColor(sf::Color::Blue);
	m_scoreTextRenderComponent->SetCharacterSizePixels(GameEngine::GameEngineMain::GetPixelHeight(4.f));
	m_scoreTextRenderComponent->SetFillColor(sf::Color::Transparent);
	m_scoreTextRenderComponent->SetZLevel(1);

	m_scoreTextRenderComponent->SetString(score);
}


ScoreEntity::~ScoreEntity()
{

}


void ScoreEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();
}


void ScoreEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();
}
