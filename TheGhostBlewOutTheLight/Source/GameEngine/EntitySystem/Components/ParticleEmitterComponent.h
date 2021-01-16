#pragma once
#include <SFML/System/Vector2.hpp>

#include "GameEngine/EntitySystem/Component.h"
#include "GameEngine/Util/TextureManager.h"
#include "GameEngine/Util/AnimationManager.h"

#include <vector>

namespace GameEngine
{	
	struct SParticleDefinition
	{
		SParticleDefinition()
			: m_texture(eTexture::None)
			, m_zLevel(0)
			, m_size(sf::Vector2f(0.f, 0.f))
			, m_animId(EAnimationId::None)
			, m_lifeTime(0.f)
		{

		}

		SParticleDefinition(eTexture::type texture, int zLev, sf::Vector2f size, EAnimationId::type animId, float lifeTime)
			: m_texture(texture)
			, m_zLevel(zLev)
			, m_size(size)
			, m_animId(animId)
			, m_lifeTime(lifeTime)
		{

		}


		eTexture::type m_texture;
		int			   m_zLevel;
		sf::Vector2f	   m_size;
		EAnimationId::type m_animId;
		float			   m_lifeTime;		
	};

	class ParticleEmitterComponent: public Component
	{
	public:
		ParticleEmitterComponent();
		virtual ~ParticleEmitterComponent();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;				

		virtual void Update() override;		
		void SetParticleDefinition(const SParticleDefinition& def) { m_particleDefinition = def; }

	protected:
		void EmitParticle();

		//Placeholder temp - should go to helpers or smth.
		float RandomFloatRange(float a, float b)
		{
			return ((b - a) * ((float)rand() / RAND_MAX)) + a;
		}

		float m_toEmitTimer;
		float m_maxTimeToEmit;
		float m_minTimeToEmit;		

		SParticleDefinition m_particleDefinition;
	};
}

