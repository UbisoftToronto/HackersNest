#include "VirusMovementComponent.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Entity.h"

#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

#include <iostream>
#include <string>

using namespace Game;

VirusMovementComponent::VirusMovementComponent()
: isGoingRight(true)
{

}

VirusMovementComponent::~VirusMovementComponent()
{
  
}

void VirusMovementComponent::OnAddToWorld()
{
}

void VirusMovementComponent::Update()
{
  Component::Update();

  sf::Vector2f pos = GetEntity()->GetPos();

  if (isGoingRight) pos += sf::Vector2f(0.75f, 0.f);
  else pos -= sf::Vector2f(0.75f, 0.f);

  if (pos.x <= startPos.x) {
    pos.x = startPos.x;
    velocity.x = 0;
    isGoingRight = true;
  }

  if (pos.x >= endPos.x) {
    pos.x = endPos.x;
    velocity.x = 0;
    isGoingRight = false;
  }

  GetEntity()->SetPos(pos);
}
