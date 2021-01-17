#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

namespace Game
{
  class Wall : public GameEngine::Entity
  {
  public:
    Wall(sf::Vector2f size, sf::Vector2f pos);
    Wall(GameEngine::eTexture::type textureType, sf::Vector2f size, sf::Vector2f pos);
    ~Wall();
    virtual void OnAddToWorld();
		virtual void OnRemoveFromWorld();

		virtual void Update();
  private:
    GameEngine::SpriteRenderComponent* renderTextureComponent;  //Initalized if texture is provided
    GameEngine::RenderComponent* renderComponent;
  };
}


