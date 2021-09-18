#include "PlatformEntity.h"

#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Components/ButtonComponent.h"

#include <SFML/Graphics.hpp>

using namespace Game;

PlatformEntity::PlatformEntity()	
{
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetFillColor(sf::Color::Red);
	m_renderComponent->SetTexture(GameEngine::eTexture::Tileset);
	m_renderComponent->SetZLevel(2);
	m_renderComponent->SetTileIndex(0, 0);

	AddComponent<GameEngine::CollidableComponent>();
	AddComponent<GameEngine::ButtonComponent>();

	SetEntityTag("Platform");
}


PlatformEntity::~PlatformEntity()
{

}


void PlatformEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();
}


void PlatformEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();
}
