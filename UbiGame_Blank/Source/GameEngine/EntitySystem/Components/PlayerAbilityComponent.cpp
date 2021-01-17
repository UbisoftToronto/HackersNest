
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
            GetEntity()->hooking = true;
            GetEntity()->netting = false;
            GetEntity()->dodging = false; 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && GetEntity()->netDown <= 0.f) {
            GetEntity()->hooking = false;
            GetEntity()->netting = true;
            GetEntity()->dodging = false;
 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && GetEntity()->dodgeDown <= 0.f) {
            GetEntity()->hooking = false;
            GetEntity()->netting = false;
            GetEntity()->dodging = true;

        }

        GetEntity()->isAbility = GetEntity()->hooking;
    }


    if (GetEntity()->hooking) {
        if (hook != nullptr) {
            if (hook->retractTime <= 0.f) {
                hook = nullptr;
                GetEntity()->hooking = false;
                GetEntity()->isAbility = false;
            }
        } else {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    GameEngine::Entity* e = new GameEngine::Entity();
	                GameEngine::GameEngineMain::GetInstance()->AddEntity(e);
	                e->SetPos(GetEntity()->GetPos());  // <-- Move its initial position
	                e->SetSize(sf::Vector2f(32.0f, 32.0f)); // <-- Make the square bigger
                    hook = static_cast<HookComponent*>
                    (e->AddComponent<HookComponent>());

                    e->AddComponent<GameEngine::CollidableComponent>(); //hoping to god this adds the collision box

                    GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
                    (e->AddComponent<GameEngine::SpriteRenderComponent>());
                    GameEngine::SpriteRenderComponent* spriteRender = e->AddComponent<GameEngine::SpriteRenderComponent>();

                    spriteRender->SetFillColor(sf::Color::Transparent);
                    spriteRender->SetTexture(GameEngine::eTexture::Player);

                    sf::Vector2f displacement{ 0.0f,0.0f };

                    sf::Vector2f windowPos{ static_cast<float>(GetEntity()->window->getPosition().x),  static_cast<float>(GetEntity()->window->getPosition().y) };

                    sf::Vector2f mousePos{ static_cast<float>(sf::Mouse::getPosition().x),  static_cast<float>(sf::Mouse::getPosition().y) };

                    sf::Vector2f pos_diff = mousePos - e->GetPos() - windowPos;

                    // Find the length of the pos_diff vector
                    float vector_length = sqrt(pos_diff.x * pos_diff.x + pos_diff.y * pos_diff.y);

                    sf::Vector2f unit{0.f,1.f};

                    float dot = pos_diff.x*unit.x + pos_diff.y*unit.y;
                    float det = pos_diff.x*unit.y - pos_diff.y*unit.x;
                    float angle = 180*atan(dot/det)/3.14;
                    if(pos_diff.x < 0){
                        angle += 180;
                    }
                    e->SetRotation(angle);

                    displacement.x += (pos_diff.x / vector_length);
                    displacement.y += (pos_diff.y / vector_length);


                    hook->liveTime = 2.5f;
                    hook->retractTime = 2.1f;
                    hook->destination_x = displacement.x;
                    hook->destination_y = displacement.y;

                    GetEntity()->hookDown = 8.f;
            }
        }
    }

    if (GetEntity()->netting) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    GameEngine::Entity* e = new GameEngine::Entity();
	                GameEngine::GameEngineMain::GetInstance()->AddEntity(e);
	                e->SetPos(GetEntity()->GetPos());  // <-- Move its initial position
	                e->SetSize(sf::Vector2f(64.0f, 64.0f)); // <-- Make the square bigger
                    NetComponent* net = static_cast<NetComponent*>
                    (e->AddComponent<NetComponent>());

                    GameEngine::SpriteRenderComponent* spriteRender = e->AddComponent<GameEngine::SpriteRenderComponent>();
                    
                    spriteRender->SetFillColor(sf::Color::Transparent);
                    spriteRender->SetTexture(GameEngine::eTexture::Player);

                    net->liveTime = 3.5f;
                    net->destination_x = static_cast<float>(sf::Mouse::getPosition().x);
                    net->destination_y = static_cast<float>(sf::Mouse::getPosition().y);
                    GetEntity()->netDown = 10.f;
                    GetEntity()->netting = false;
            }
    }

    if (GetEntity()->dodging) {

            GetEntity()->dodgeDown = 10.f;
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