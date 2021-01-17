#pragma once
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

    //By default the displacement is 0,0
    sf::Vector2f displacement{ 0.0f,0.0f };

    //The amount of speed that we will apply when input is received
    const float inputAmount = 100.0f;

    //std::cout << sf::Mouse::getPosition().x << sf::Mouse::getPosition().y  << std::endl;
    sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition().x),  static_cast<float>(sf::Mouse::getPosition().y) };
    //sf::Window::getPosition();
    sf::Vector2f windowPos{ static_cast<float>(GetEntity()->window->getPosition().x),  static_cast<float>(GetEntity()->window->getPosition().y) };
    sf::Vector2f clickPos = mousePos - windowPos;
    sf::Vector2f pos_diff = mousePos - GetEntity()->GetPos() - windowPos;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        displacement.x += pos_diff.x * dt;
        displacement.y += pos_diff.y * dt;
    }
    
    if (!GetEntity()->isAbility) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && GetEntity()->hookDown < 0.f) {
            GetEntity()->hooking = !GetEntity()->hooking;
            GetEntity()->netting = false;
            GetEntity()->dodging = false;
            if (GetEntity()->hooking) {
                GetEntity()->isAbility = true;
            } else {
                GetEntity()->isAbility = false;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && GetEntity()->netDown < 0.f) {
            GetEntity()->hooking = false;
            GetEntity()->netting = !GetEntity()->netting;
            GetEntity()->dodging = false;
                        if (GetEntity()->hooking) {
                GetEntity()->isAbility = true;
            } else {
                GetEntity()->isAbility = false;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && GetEntity()->dodgeDown < 0.f) {
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
            if (hook->retractTime > 0) {
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

                    spriteRender->SetTexture(GameEngine::eTexture::Hook);

                   sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition().x),  static_cast<float>(sf::Mouse::getPosition().y) };
                    hook->liveTime = 4.f;
                    hook->retractTime = 2.f;
                    hook->destination_x = mousePos.x;
                    hook->destination_y = mousePos.y;


            }
        }
    }

}

void PlayerAbilityComponent::OnAddToWorld() {}