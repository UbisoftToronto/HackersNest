#pragma once

#include <GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h>

namespace Game 
{
	class ProjectilePhysicsComponent : public GameEngine::CollidablePhysicsComponent
	{
	public:
		ProjectilePhysicsComponent();
		~ProjectilePhysicsComponent();

		virtual void Update() override;

		void setVelocity(sf::Vector2f velocity);
		void setDirectionVector(sf::Vector2f vector);

	private:
		void updateProjectileHit();

		sf::Vector2f velocity;
		sf::Vector2f directionVector;
	};
}