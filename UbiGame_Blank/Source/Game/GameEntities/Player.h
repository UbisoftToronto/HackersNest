#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include <Game/GameComponents/PlayerMovementComponent.h>
#include <Game/GameComponents/PlayerActionComponent.h>

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
		void setActionButton(int actionButton);

	private:
		int playerHealth;

		// Components 
		Game::PlayerMovementComponent* movementComponent;
		Game::PlayerActionComponent* actionComponent;
	};
}
