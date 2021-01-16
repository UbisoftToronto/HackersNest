#include "TextRenderComponent.h"

#include <assert.h>

#include "GameEngine/GameEngineMain.h"

using namespace GameEngine;

TextRenderComponent::TextRenderComponent()
{
}

TextRenderComponent::~TextRenderComponent()
{
}

void TextRenderComponent::Render(sf::RenderTarget* target)
{
    RenderComponent::Render(target);

    if (!target)
    {
        return;
    }

    m_text.setPosition(GetEntity()->GetPos());
    m_text.setRotation(GetEntity()->GetRot());
    target->draw(m_text);
}

void TextRenderComponent::SetString(std::string displayString)
{
    m_text.setString(displayString);
}

void TextRenderComponent::SetFont(std::string fontFile)
{
    std::string filePath;
    filePath.append("Resources/fonts/");
    filePath.append(fontFile);
    if (!m_font.loadFromFile(filePath))
    {
        assert(false);  // Drop an assert if we are loading a font that doesn't exist;
    }

    m_text.setFont(m_font);
}

void TextRenderComponent::SetColor(sf::Color color)
{
    m_text.setFillColor(color);
}

void TextRenderComponent::SetCharacterSizePixels(int characterSize)
{
    // This sets the character size in pixels not points!
    m_text.setCharacterSize(characterSize);
}

void TextRenderComponent::SetStyle(int styleBitField)
{
    m_text.setStyle(styleBitField);
}

void TextRenderComponent::SetStyle(sf::Text::Style style, bool value)
{
    int styleBitField = m_text.getStyle();
    if (value)
    {
        styleBitField |= 1 << style;
    }
    else
    {
        styleBitField &= 0 << style;
    }
    m_text.setStyle(styleBitField);
}
