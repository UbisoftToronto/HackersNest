#pragma once
#include "GameEngine/EntitySystem/Component.h"
#include <SFML/System/Vector2.hpp>

namespace Game 
{
  class TimerMovementComponent: public GameEngine::Component
  {
    public:
      TimerMovementComponent();
      ~TimerMovementComponent();

      virtual void Update() override;
      virtual void OnAddToWorld() override;
  };
}