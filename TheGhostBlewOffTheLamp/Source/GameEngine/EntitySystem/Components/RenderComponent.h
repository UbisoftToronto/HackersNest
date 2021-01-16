#pragma once
#include <SFML/Graphics.hpp>
#include "GameEngine/EntitySystem/Component.h"

namespace GameEngine
{
	class CollidableComponent;

	class RenderComponent : public Component
	{
	public:
		RenderComponent();
		virtual ~RenderComponent();

		virtual void Update() override;
		virtual void Render(sf::RenderTarget* target);

		void SetFillColor(sf::Color fill) { m_fillColor = fill; }
		
		void SetZLevel(int level) { m_zLevel = level; }
		int  GetZLevel() const { return m_zLevel; }

	private:
		sf::Color m_fillColor;
		int m_zLevel;
	};
}


