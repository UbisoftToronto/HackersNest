#pragma once
#include "GameEngine/EntitySystem/Component.h"

namespace Game
{
	class PlayerCameraComponent : public GameEngine::Component
	{
	public:
		PlayerCameraComponent();
		virtual ~PlayerCameraComponent();

		virtual void Update() override;
		virtual void OnAddToWorld() override;		

	private:		
	};
}


