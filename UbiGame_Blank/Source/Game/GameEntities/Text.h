#pragma once
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"


class Text : public GameEngine::Entity
{
public:
    Text(std::string text, sf::Color color, int fontSize, sf::Vector2f position);
    ~Text();

    void OnAddToWorld() override;
    void OnRemoveFromWorld() override;

protected:
    GameEngine::TextRenderComponent* textRenderComponent;

};