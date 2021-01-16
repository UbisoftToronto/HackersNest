#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

namespace Game
{
	class BallEntity : public GameEngine::Entity
	{
	public:
		BallEntity();
		~BallEntity();

	protected:
		// Add components
		GameEngine::SpriteRenderComponent* m_renderComponent;
	};
}