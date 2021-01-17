#pragma once
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

namespace GameEngine
{
	//This one allows for movement and obstacle detection, 
	class BallCollideComponent : public CollidablePhysicsComponent
	{
	public:
		BallCollideComponent();
		virtual ~BallCollideComponent();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

		virtual void Update() override;

		Entity* GetBall() const { return ball; }

	private:
		Entity* ball;
	};
}

