#pragma once
#include "GameEngine/EntitySystem/Component.h"

namespace Game
{
	class Paddlemovement :public GameEngine::Component
	{
	public:
		Paddlemovement();
		~Paddlemovement();

		virtual void Update() override;
		virtual void OnAddToWorld() override;

	private:

	};
}
