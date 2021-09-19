#include "VirusEntity.h"
#include <SFML/System/Vector2.hpp>
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "GameEngine/EntitySystem/Components/ParticleEmitterComponent.h"
#include "GameEngine/EntitySystem/Components/SoundComponent.h"

using namespace Game;

VirusEntity::VirusEntity(sf::Vector2f startPos,sf::Vector2f endPos)
{
  m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
  m_renderComponent->SetTexture(GameEngine::eTexture::Virus);

  GameEngine::CollidablePhysicsComponent* cpc = AddComponent<GameEngine::CollidablePhysicsComponent>();

  hitBullet = false;

  m_virusMovementComponent = AddComponent<VirusMovementComponent>();
  m_virusMovementComponent->SetStartAndEndPos(startPos, endPos);

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