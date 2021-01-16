#include "Text.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"

Text::Text(std::string text, sf::Color color, int fontSize, sf::Vector2f position) {
    textRenderComponent = AddComponent<GameEngine::TextRenderComponent>();
    textRenderComponent -> SetFont("pixelFont.ttf");
    textRenderComponent -> SetColor(color);
    textRenderComponent -> SetCharacterSizePixels(fontSize);
    textRenderComponent -> SetString(text);

    this->SetPos(position);
}

Text::~Text() {

}



void Text::OnAddToWorld() {
    Entity::OnAddToWorld();
}

void Text::OnRemoveFromWorld() {
    Entity::OnRemoveFromWorld();
}
