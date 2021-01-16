#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"

namespace Game
{

	class ScoreEntity : public GameEngine::Entity
	{
	public:
		ScoreEntity(std::string score);
		~ScoreEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

	protected:
		GameEngine::TextRenderComponent* m_scoreTextRenderComponent;
	};
}

