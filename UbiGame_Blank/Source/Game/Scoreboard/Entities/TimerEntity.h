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
		virtual void Update() override;

		virtual int GetSecondsRemaining() { return secondsRemaining; };

	protected:
		GameEngine::TextRenderComponent* m_timerTextRenderComponent;
		// Number of seconds set on the timer;
		int timerSeconds;
		int secondsRemaining;
		time_t startTimeInSeconds;
	};
}

