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

		void SetXDirection(float x) { xDirection = x; }
		void SetYDirection(float y) { yDirection = y; }
		float GetXDirection() { return xDirection; }
		float GetYDirection() { return yDirection; }

	private:
		float xDirection;
		float yDirection;
		float speed;
	};
}