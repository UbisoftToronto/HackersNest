#pragma once

#include "GameEngine/EntitySystem/Entity.h"
#include <Game/GameComponents/ProjectilePhysicsComponent.h>


namespace Game 
{
	class Bullet : public GameEngine::Entity
	{
	public:
		Bullet();

		virtual void OnAddToWorld();
		virtual void OnRemoveFromWorld();

		virtual void Update();

		void setDirectionVector(sf::Vector2f vector);
		void setOwner(GameEngine::Entity* entity);
		GameEngine::Entity* getOwner();
	private:
		GameEngine::Entity* owner;
		Game::ProjectilePhysicsComponent* projectilePhysicsComponent;
	};
}
