#include "ParticleEmitterComponent.h"

#include "GameEngine/EntitySystem/Components/ParticleComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/AnimationComponent.h"
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/GameEngineMain.h"

#include <SFML/System/Vector2.hpp>


using namespace GameEngine;

ParticleEmitterComponent::ParticleEmitterComponent()
: m_toEmitTimer(0.f)
, m_maxTimeToEmit(0.3f)
, m_minTimeToEmit(0.1f)
{

}


ParticleEmitterComponent::~ParticleEmitterComponent()
{

}


void ParticleEmitterComponent::Update()
{	
	float dt = GameEngine::GameEngineMain::GetInstance()->GetTimeDelta();
	m_toEmitTimer -= dt;

	if (m_toEmitTimer <= 0.f)
	{
		EmitParticle();

		m_toEmitTimer = RandomFloatRange(m_minTimeToEmit, m_maxTimeToEmit);
	}
}

void ParticleEmitterComponent::OnAddToWorld()
{
	Component::OnAddToWorld();
}


void ParticleEmitterComponent::OnRemoveFromWorld()
{
	Component::OnAddToWorld();
}


void ParticleEmitterComponent::EmitParticle()
{
	//This is just an example of particle emitting snippet
	sf::Vector2f emitPos = GetEntity()->GetPos();

	Entity* particleEntity = new Entity();
	SpriteRenderComponent* render = particleEntity->AddComponent<SpriteRenderComponent>();
	ParticleComponent* particleCMP = particleEntity->AddComponent<ParticleComponent>();
	AnimationComponent* animComponent = particleEntity->AddComponent<AnimationComponent>();

	render->SetTexture(m_particleDefinition.m_texture);
	render->SetZLevel(m_particleDefinition.m_zLevel);

	particleEntity->SetPos(emitPos);
	particleEntity->SetSize(m_particleDefinition.m_size);

	animComponent->PlayAnim(m_particleDefinition.m_animId);

	particleCMP->SetLifeTime(m_particleDefinition.m_lifeTime);

	GameEngineMain::GetInstance()->AddEntity(particleEntity);
}
