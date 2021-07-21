#pragma once
#include <SFML/System/Vector2.hpp>
#include "GameEngine/Util/TextureManager.h"

#include <vector>

namespace GameEngine
{		
	struct SAnimationDefinition;	
	namespace EAnimationId
	{
		enum type
		{
			BirdIdle,
			BirdFly,
			Smoke,
			None,
		};
	}

	class AnimationManager
	{
	public:		
		~AnimationManager();

		static AnimationManager* GetInstance() { if (!sm_instance) sm_instance = new AnimationManager(); return sm_instance; }

		void InitStaticGameAnimations();
		void ReleaseStaticGameAnimations();

		const SAnimationDefinition* GetAnimDefinition(EAnimationId::type animId) const;

	private:
		AnimationManager();
		static AnimationManager* sm_instance;

		std::vector<SAnimationDefinition> m_animDefinitions;
	};

	struct SAnimationDefinition
	{
		EAnimationId::type m_animId;
		eTexture::type m_texture;
		sf::Vector2i m_startTile;
		int			 m_frameCount;
		int		     m_fps;

		SAnimationDefinition()
			: m_animId(EAnimationId::None)
			, m_texture(eTexture::None)
			, m_startTile(sf::Vector2i(0, 0))
			, m_frameCount(5)
			, m_fps(20)			
		{

		}

		SAnimationDefinition(EAnimationId::type animId, eTexture::type texture, sf::Vector2i startTile, int frameCount, int fps )
			: m_animId(animId)
			, m_texture(texture)
			, m_startTile(startTile)
			, m_frameCount(frameCount)
			, m_fps(fps)
		{

		}
	};
}
