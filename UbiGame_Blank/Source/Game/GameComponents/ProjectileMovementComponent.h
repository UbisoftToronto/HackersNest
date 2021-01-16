#pragma once

#include "GameEngine/EntitySystem/Component.h"
#include <SFML/Graphics.hpp>

namespace Game 
{
	class ProjectileMovementComponent : public GameEngine::Component
	{
	public:
		virtual void Update();
		virtual void OnAddToWorld();

		void setVelocity(sf::Vector2f velocity);
	private:
		sf::Vector2f velocity;
	};
}
