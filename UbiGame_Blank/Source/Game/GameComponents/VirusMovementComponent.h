#pragma once
#include "GameEngine/EntitySystem/Component.h"
#include <SFML/System/Vector2.hpp>

namespace Game 
{
  class VirusMovementComponent: public GameEngine::Component
  {
    public:
      VirusMovementComponent();
      ~VirusMovementComponent();

      virtual void Update() override;
      virtual void OnAddToWorld() override;
      void SetStartAndEndPos(sf::Vector2f start, sf::Vector2f end) { 
        startPos = start; endPos = end;
      };
    
    private:
      sf::Vector2f velocity;
      sf::Vector2f startPos;
      sf::Vector2f endPos;

      bool isGoingRight;
  };
}