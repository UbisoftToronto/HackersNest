#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include "GameEngine/EntitySystem/Components/RenderComponent.h"
#include "GameEngine/EntitySystem/Components/AnimationComponent.h"
#include "GameEngine/Util/TextureManager.h"

namespace GameEngine
{	
	class SpriteRenderComponent : public RenderComponent
	{
	public:
		SpriteRenderComponent();
		virtual ~SpriteRenderComponent();

		virtual void Update() override;
		
		virtual void Render(sf::RenderTarget* target) override;
		virtual void OnAddToWorld() override;

		void SetTexture(eTexture::type texture);

		//For Tilled texture support, can be ignored for simple one file textures
		void SetTileIndex(sf::Vector2i vect) { m_tileIndex = vect; }
		void SetTileIndex(int xIdx, int yIdx) { m_tileIndex = sf::Vector2i(xIdx, yIdx); }		

	private:
		void UpdateTileRect();
		void UpdateSpriteParams();

		eTexture::type  m_texture;
		sf::Vector2i	m_tileIndex;

		sf::Sprite m_sprite;
		//Only needed if animation is supported for entity
		AnimationComponent* m_animComponent;
	};
}


