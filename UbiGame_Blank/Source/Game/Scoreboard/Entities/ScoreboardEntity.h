#pragma once
#include <vector>
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/RenderComponent.h"
#include "ScoreEntity.h"
#include "TimerEntity.h"

namespace Game
{

	class ScoreboardEntity : public GameEngine::Entity
	{
	public:
		ScoreboardEntity();
		~ScoreboardEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

		virtual void InitScoreboard();
		// Call this method to update the score
		virtual void UpdateScore(int playerNumber, int score); 
		virtual int GetSecondsRemaining() { return timer->GetSecondsRemaining(); };

	protected:
		GameEngine::RenderComponent* m_renderComponent;
		std::vector<ScoreEntity*> scores;
		TimerEntity* timer;
	};
}

