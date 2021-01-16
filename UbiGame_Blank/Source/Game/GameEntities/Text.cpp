#include "Text.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"

using namespace Game;

Text::Text(std::string text, sf::Color color, int fontSize, sf::Vector2f position) 
{
    textRenderComponent = AddComponent<GameEngine::TextRenderComponent>();
    textRenderComponent -> SetFont("pixelFont.ttf");
    textRenderComponent -> SetColor(color);
    textRenderComponent -> SetCharacterSizePixels(fontSize);
    textRenderComponent -> SetString(text);

    this->SetPos(position);
}

Text::~Text() 
{
}

void Text::setText(std::string text)
{
  textRenderComponent -> SetString(text);
  }



void Text::OnAddToWorld() 
{
    Entity::OnAddToWorld();
}

void Text::OnRemoveFromWorld() 
{
    Entity::OnRemoveFromWorld();
}
