#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/RenderComponent.h"

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

	protected:
		GameEngine::RenderComponent* m_renderComponent;
	};
}

