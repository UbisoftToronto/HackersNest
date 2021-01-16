#pragma once
#include "GameEngine/EntitySystem/Component.h"
//Paddlemovement 2
namespace Game
{
	class Paddlemovement2 :public GameEngine::Component
	{
	public:
		Paddlemovement2();
		~Paddlemovement2();

		virtual void Update() override;
		virtual void OnAddToWorld() override;

	private:

	};
}
