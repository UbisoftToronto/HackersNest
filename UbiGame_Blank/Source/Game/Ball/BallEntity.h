#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine//EntitySystem/Components/CollidablePhysicsComponent.h"
#include "Game/Ball/BallComponents/BallMovementComponent.h"
#include "Game/Ball/BallComponents/BallCollideComponent.h"

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
		BallMovementComponent* ballMovementComponent;
		GameEngine::BallCollideComponent* ball;
	};
}