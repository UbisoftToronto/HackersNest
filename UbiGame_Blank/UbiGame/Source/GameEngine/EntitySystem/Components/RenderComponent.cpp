#include "RenderComponent.h"

#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/GameEngineMain.h"

#include <SFML/System/Vector2.hpp>

using namespace GameEngine;

RenderComponent::RenderComponent()
	: m_fillColor(sf::Color::Green)
	, m_zLevel(0)
{

}


RenderComponent::~RenderComponent()
{

}


void RenderComponent::Update()
{

}

void RenderComponent::Render(sf::RenderTarget* target)
{
	if (!target)
	{
		return;
	}

	//Change that to true, whenever you need the BASIC shape rendering to be active
	static bool drawDebug = true;	
	
	//Debug draw of bounding boxes
	if (drawDebug)
	{
		//Debug draw of entity pos
		sf::RectangleShape shape(GetEntity()->GetSize());
		sf::Vector2f pos = GetEntity()->GetPos();
		pos -= shape.getSize() / 2.f;
		shape.setFillColor(m_fillColor);
		shape.setPosition(pos);

		target->draw(shape);
	}	
}