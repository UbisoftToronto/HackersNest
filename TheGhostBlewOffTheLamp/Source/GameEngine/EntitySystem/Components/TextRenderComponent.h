#pragma once
#include "GameEngine/EntitySystem/Components/RenderComponent.h"

namespace GameEngine
{
    class TextRenderComponent : public RenderComponent
    {
    public:
        TextRenderComponent();
        ~TextRenderComponent();

        virtual void Render(sf::RenderTarget* target) override;

        void SetString(std::string displayString);
        void SetFont(std::string fontFile);
        void SetColor(sf::Color color);
        void SetCharacterSizePixels(int characterSize);

        void SetStyle(int styleBitField);
        void SetStyle(sf::Text::Style style, bool value);

    private:
        sf::Text m_text;
        sf::Font m_font;
    };
}  // namespace GameEngine
