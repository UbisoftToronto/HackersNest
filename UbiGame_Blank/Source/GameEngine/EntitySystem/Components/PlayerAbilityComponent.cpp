
#include "PlayerAbilityComponent.h"
#include <SFML/Window/Keyboard.hpp>   //<-- Add the keyboard include in order to get keyboard inputs
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>
#include "GameEngine/GameEngineMain.h" //<-- Add this include to retrieve the delta time between frames

using namespace Game;

void PlayerAbilityComponent::Update()
{
    Component::Update();

    //Grabs how much time has passed since last frame
    const float dt = GameEngine::GameEngineMain::GetTimeDelta();

    if (!GetEntity()->isAbility) {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && GetEntity()->hookDown <= 0.f) {
            GetEntity()->hooking = !GetEntity()->hooking;
            GetEntity()->netting = false;
            GetEntity()->dodging = false;
            std::cout << "A";
            if (GetEntity()->hooking) {
                GetEntity()->isAbility = true;
            } else {
                GetEntity()->isAbility = false;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && GetEntity()->netDown <= 0.f) {
            GetEntity()->hooking = false;
            GetEntity()->netting = !GetEntity()->netting;
            GetEntity()->dodging = false;
                        if (GetEntity()->hooking) {
                GetEntity()->isAbility = true;
            } else {
                GetEntity()->isAbility = false;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && GetEntity()->dodgeDown <= 0.f) {
            GetEntity()->hooking = false;
            GetEntity()->netting = false;
            GetEntity()->dodging = true;
                        if (GetEntity()->hooking) {
                GetEntity()->isAbility = true;
            } else {
                GetEntity()->isAbility = false;
            }
        }
    }

    if (GetEntity()->hooking) {
        if (hook != nullptr) {
            if (hook->retractTime > 0.f) {
                hook = nullptr;
                GetEntity()->hooking = false;
            }
        } else {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                
                    GameEngine::Entity* e = new GameEngine::Entity();
	                GameEngine::GameEngineMain::GetInstance()->AddEntity(e);
	
	                e->SetPos(GetEntity()->GetPos());  // <-- Move its initial position
	                e->SetSize(sf::Vector2f(50.0f, 50.0f)); // <-- Make the square bigger

                    hook = static_cast<HookComponent*>
                    (e->AddComponent<HookComponent>());

                    GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
                    (e->AddComponent<GameEngine::SpriteRenderComponent>());

                    spriteRender->SetFillColor(sf::Color::Red);
                    spriteRender->SetTexture(GameEngine::eTexture::Hook);

                   sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition().x),  static_cast<float>(sf::Mouse::getPosition().y) };
                    hook->liveTime = 4.f;
                    hook->retractTime = 2.f;
                    hook->destination_x = mousePos.x;
                    hook->destination_y = mousePos.y;


            }
        }
    }

    if (GetEntity()->hookDown > 0.f) {
        GetEntity()->hookDown -= dt;
    }
    if (GetEntity()->dodgeDown > 0.f) {
        GetEntity()->dodgeDown -= dt;
    }
    if (GetEntity()->netDown > 0.f) {
        GetEntity()->netDown -= dt;
    }

}

void PlayerAbilityComponent::OnAddToWorld() {};