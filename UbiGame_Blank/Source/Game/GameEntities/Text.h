#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"

namespace Game 
{
    class Text : public GameEngine::Entity
    {
    public:
        Text(std::string text, sf::Color color, int fontSize, sf::Vector2f position);
        ~Text();

        void OnAddToWorld() override;
        void OnRemoveFromWorld() override;
        void setText(std::string);

    protected:
        GameEngine::TextRenderComponent* textRenderComponent;

    };
}
