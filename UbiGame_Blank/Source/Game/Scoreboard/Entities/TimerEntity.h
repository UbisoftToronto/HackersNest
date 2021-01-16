#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"

namespace Game
{

	class TimerEntity : public GameEngine::Entity
	{
	public:
		TimerEntity(int seconds);
		~TimerEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

	protected:
		GameEngine::TextRenderComponent* m_timerTextRenderComponent;
	};
}

