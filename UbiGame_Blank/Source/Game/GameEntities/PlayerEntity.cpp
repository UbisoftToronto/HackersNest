#include "PlayerEntity.h"

#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "GameEngine/EntitySystem/Components/ParticleEmitterComponent.h"
#include "GameEngine/EntitySystem/Components/SoundComponent.h"
#include "GameEngine/Util/AnimationManager.h"

using namespace Game;

PlayerEntity::PlayerEntity()
{

	//Render 
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();	
	m_renderComponent->SetTexture(GameEngine::eTexture::Player);
	m_renderComponent->SetZLevel(2);

	//Animation
	m_animComponent = AddComponent<GameEngine::AnimationComponent>();
		

}

 
PlayerEntity::~PlayerEntity()
{

}
