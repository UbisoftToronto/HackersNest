#pragma once
#include "GameEngine/EntitySystem/Component.h"

namespace Game
{
	class BallMovementComponent : public GameEngine::Component
	{
	public:
		BallMovementComponent();
		~BallMovementComponent();

		virtual void Update() override;
		virtual void OnAddToWorld() override;

	private:
		float xDirection;
		float yDirection;
		float speed;
	};
}