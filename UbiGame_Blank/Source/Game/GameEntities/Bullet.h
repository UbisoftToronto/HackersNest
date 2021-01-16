#pragma once

#include "GameEngine/EntitySystem/Entity.h"


namespace Game 
{
	class Bullet : public GameEngine::Entity
	{
	public:
		Bullet();

		virtual void OnAddToWorld();
		virtual void OnRemoveFromWorld();

		virtual void Update();
	private:

	};
}
