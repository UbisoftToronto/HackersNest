#pragma once
#include "GameEngine/EntitySystem/Component.h"
#include "GameEngine/Util/AnimationManager.h"

namespace GameEngine
{		
	class AnimationComponent : public Component
	{
	public:
		AnimationComponent();
		virtual ~AnimationComponent();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

		void PlayAnim(EAnimationId::type animId);
		virtual void Update() override;		
		sf::Vector2i GetWantedTileIndex() const;

		bool IsAnimPlaying() const;
		EAnimationId::type GetCurrentAnimation() const { return m_currentAnim; }

	protected:
		EAnimationId::type m_currentAnim;
		int m_currentFrame;
		float m_currentFrameDT;
	};
}

