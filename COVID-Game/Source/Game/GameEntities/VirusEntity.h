#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include <SFML/System/Vector2.hpp>
#include "GameEngine/EntitySystem/Components/AnimationComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "Game/GameComponents/VirusMovementComponent.h"

namespace Game
{
  class VirusEntity: public GameEngine::Entity
  {
  public:
    VirusEntity(sf::Vector2f, sf::Vector2f);
    ~VirusEntity();

    bool hitBullet;

    virtual void OnAddToWorld() override;
    virtual void OnRemoveFromWorld() override;

    GameEngine::AnimationComponent* m_animComponent;
    GameEngine::SpriteRenderComponent* m_renderComponent;
  
  protected:
  VirusMovementComponent* m_virusMovementComponent;
  };
}