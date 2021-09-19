#include "TimerMovementComponent.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Entity.h"

#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

#include <iostream>
#include <string>

using namespace Game;

TimerMovementComponent::TimerMovementComponent()
{

}

TimerMovementComponent::~TimerMovementComponent()
{
  
}

void TimerMovementComponent::OnAddToWorld()
{
}

void TimerMovementComponent::Update()
{
  Component::Update();

  sf::Vector2f pos = GetEntity()->GetPos();

 if (pos.x == -250.f) {
    std::cout << pos.x << "\n";
  }

  pos -= sf::Vector2f(0.2f, 0.f);

  GetEntity()->SetPos(pos);
}
