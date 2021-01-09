#include "ImageClickComponent.h"
#include "GameEngine/GameEngineMain.h"
#include <SFML/Window/Mouse.hpp>

using namespace Game;

void ImageClickComponent::Update()
{
    Component::Update();

    //Grabs how much time has passed since last frame
    const float dt = GameEngine::GameEngineMain::GetTimeDelta();


    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        //Update the entity position
        GetEntity()->SetClicked(true);
    }
    else
    {
        //Update the entity position
        GetEntity()->SetClicked(false);
    }


}

void ImageClickComponent::OnAddToWorld() {}