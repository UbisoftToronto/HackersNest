#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include <Game/GameComponents/PlayerMovementComponent.h>

namespace Game 
{
	class Player : public GameEngine::Entity
	{
	public:
		Player();
		virtual void OnAddToWorld();
		virtual void OnRemoveFromWorld();

		virtual void Update();

		void setControls(int controls[4]);

	private:
		int playerHealth;
		Game::PlayerMovementComponent* movementComponent;
	};
}
