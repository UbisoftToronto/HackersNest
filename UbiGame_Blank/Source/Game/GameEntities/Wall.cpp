#include "Wall.h"

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

Game::Wall::Wall(int textureType, sf::Vector2f size, sf::Vector2f pos)
{

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
