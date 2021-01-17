#include "Wall.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"

Game::Wall::Wall(sf::Vector2f size, sf::Vector2f pos)
{
  setEntityType(GameEngine::EntityType::WALL);
  SetSize(size);
  SetPos(pos);

  AddComponent<GameEngine::CollidableComponent>();

  //Render no sprite
  renderComponent = AddComponent<GameEngine::RenderComponent>();
  renderComponent -> SetFillColor(sf::Color::Transparent);
}

Game::Wall::Wall(GameEngine::eTexture::type textureType, sf::Vector2f size, sf::Vector2f pos)
{
  setEntityType(GameEngine::EntityType::WALL);
  SetSize(size);
  SetPos(pos);

  AddComponent<GameEngine::CollidableComponent>();

  //Render no sprite
  renderTextureComponent = AddComponent<GameEngine::SpriteRenderComponent>();
  renderTextureComponent -> SetTexture(textureType);
  renderTextureComponent -> SetFillColor(sf::Color::Transparent);
}

Game::Wall::~Wall()
{
  
}

void Game::Wall::OnAddToWorld() 
{
	Entity::OnAddToWorld();
}

void Game::Wall::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();
}

void Game::Wall::Update()
{
	Entity::Update();
}
