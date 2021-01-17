#pragma once
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include <string.h>

namespace GameEngine
{
	//This one allows for movement and obstacle detection, 
	class CollidablePhysicsComponent : public CollidableComponent
	{
	public:
		CollidablePhysicsComponent();
		virtual ~CollidablePhysicsComponent();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;
		
		virtual void Update() override;

		void sort_collision(std::string type1);
	};
}

