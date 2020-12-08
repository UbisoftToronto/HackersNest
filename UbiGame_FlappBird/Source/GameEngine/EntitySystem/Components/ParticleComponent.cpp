#include "ParticleComponent.h"



using namespace GameEngine;

ParticleComponent::ParticleComponent()
	: m_lifeTimer(2.f)
{

}


ParticleComponent::~ParticleComponent()
{

}


void ParticleComponent::OnAddToWorld()
{
	__super::OnAddToWorld();
}


void ParticleComponent::OnRemoveFromWorld()
{
	__super::OnAddToWorld();
}


void ParticleComponent::Update()
{
	float dt = GameEngine::GameEngineMain::GetInstance()->GetTimeDelta();

	m_lifeTimer -= dt;

	if (m_lifeTimer <= 0.f)
	{
		GameEngine::GameEngineMain::GetInstance()->RemoveEntity(GetEntity());
	}
}