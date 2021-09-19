#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/AnimationComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

namespace Game
{			

	class PlayerEntity : public GameEngine::Entity
	{
	public:
		PlayerEntity();
		~PlayerEntity();


	protected:
		GameEngine::SpriteRenderComponent* m_renderComponent;		
		GameEngine::AnimationComponent* m_animComponent;
	};
}