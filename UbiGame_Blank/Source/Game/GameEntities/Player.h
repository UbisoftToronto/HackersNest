#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
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

		int getPlayerHealth() const { return playerHealth; }
		void setPlayerHealth(int health) { playerHealth = health; }

		void disableInput(bool disable);

		void addBullet(Game::Bullet* bullet);
		void clearBullets();

	private:
		int playerHealth;

		std::vector<Game::Bullet*> bullets;

		// Components 
		Game::PlayerMovementComponent* movementComponent;
		Game::PlayerActionComponent* actionComponent;
    GameEngine::SpriteRenderComponent* renderComponent;
	};
}
