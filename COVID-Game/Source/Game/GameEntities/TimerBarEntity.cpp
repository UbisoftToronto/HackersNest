#include "TimerBarEntity.h"
#include <SFML/System/Vector2.hpp>
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "GameEngine/EntitySystem/Components/ParticleEmitterComponent.h"
#include "GameEngine/EntitySystem/Components/SoundComponent.h"

using namespace Game;

TimerEntity::TimerEntity()
{
  m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
  m_renderComponent->SetTexture(GameEngine::eTexture::Timer);

  m_timerMovementComponent = AddComponent<TimerMovementComponent>();

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