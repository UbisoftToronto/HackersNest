#include "TimerEntity.h"
#include "GameEngine/GameEngineMain.h"

using namespace Game;

TimerEntity::TimerEntity(int seconds)
{
	// Render
	m_timerTextRenderComponent = AddComponent<GameEngine::TextRenderComponent>();
	m_timerTextRenderComponent->SetFont("arial.ttf");
	m_timerTextRenderComponent->SetColor(sf::Color::Blue);
	m_timerTextRenderComponent->SetCharacterSizePixels(GameEngine::GameEngineMain::GetPixelHeight(4.f));
	m_timerTextRenderComponent->SetFillColor(sf::Color::Transparent);
	m_timerTextRenderComponent->SetZLevel(2);

	m_timerTextRenderComponent->SetString(std::to_string(seconds));
}


TimerEntity::~TimerEntity()
{

}


void TimerEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();
}


void TimerEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();
}
