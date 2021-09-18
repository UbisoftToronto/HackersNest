#include "VirusEntity.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "GameEngine/EntitySystem/Components/ParticleEmitterComponent.h"
#include "GameEngine/EntitySystem/Components/SoundComponent.h"

using namespace Game;

VirusEntity::VirusEntity()
{
  m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
  m_renderComponent->SetTexture(GameEngine::eTexture::Virus);

  GameEngine::CollidablePhysicsComponent* cpc = AddComponent<GameEngine::CollidablePhysicsComponent>();

  hitBullet = false;

  //m_virusMovementComponent = AddComponent<VirusMovementComponent>();
  //m_virusMovementComponent->SetStartAndEndPos(startPos, endPos);

}

VirusEntity::~VirusEntity()
{

}

void VirusEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();
}

void VirusEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();
}