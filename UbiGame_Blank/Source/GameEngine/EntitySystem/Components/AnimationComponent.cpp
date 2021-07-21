#include "AnimationComponent.h"

#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/GameEngineMain.h"

using namespace GameEngine;

AnimationComponent::AnimationComponent()	
	: m_currentAnim(EAnimationId::None)
	, m_currentFrame(0)
	, m_currentFrameDT(0.f)
{

}


AnimationComponent::~AnimationComponent()
{

}


void AnimationComponent::OnAddToWorld()
{
	Component::OnAddToWorld();
}


void AnimationComponent::OnRemoveFromWorld()
{
	Component::OnRemoveFromWorld();
}


void AnimationComponent::Update()
{
	if (m_currentAnim == EAnimationId::None)
	{
		return;
	}

	const SAnimationDefinition* currDefinition = AnimationManager::GetInstance()->GetAnimDefinition(m_currentAnim);
	if (!currDefinition)
	{
		//TODO Assert?
		return;
	}


	float dt = GameEngineMain::GetInstance()->GetTimeDelta();
	float dt_perFrame = 1 / (float)currDefinition->m_fps;

	//Currently all anims loops by defautl, if this is not the wanted behaviour, the code below should be one to modify
	m_currentFrameDT += dt;
	if (m_currentFrameDT > dt_perFrame)
	{
		m_currentFrameDT = m_currentFrameDT - dt_perFrame;
		m_currentFrame++;		
		if (m_currentFrame >= currDefinition->m_frameCount)
			m_currentFrame = 0;
	}
}


void AnimationComponent::PlayAnim(EAnimationId::type animId)
{
	m_currentFrame = 0;
	m_currentAnim = animId;	
	m_currentFrameDT = 0.f;
}


sf::Vector2i AnimationComponent::GetWantedTileIndex() const
{
	if (m_currentAnim == EAnimationId::None)
		return sf::Vector2i(-1, -1);

	sf::Vector2i tile = AnimationManager::GetInstance()->GetAnimDefinition(m_currentAnim)->m_startTile;
	tile.x += m_currentFrame;

	return tile;
}


bool AnimationComponent::IsAnimPlaying() const
{
	return m_currentAnim != EAnimationId::None;
}