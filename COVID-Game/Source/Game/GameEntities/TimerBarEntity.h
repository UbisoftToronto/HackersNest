#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include <SFML/System/Vector2.hpp>
#include "GameEngine/EntitySystem/Components/AnimationComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "Game/GameComponents/TimerMovementComponent.h"

namespace Game
{
  class TimerEntity: public GameEngine::Entity
  {
  public:
    TimerEntity();
    ~TimerEntity();

    virtual void OnAddToWorld() override;
    virtual void OnRemoveFromWorld() override;

    GameEngine::AnimationComponent* m_animComponent;
    GameEngine::SpriteRenderComponent* m_renderComponent;
  
  protected:
  TimerMovementComponent* m_timerMovementComponent;
  };
}