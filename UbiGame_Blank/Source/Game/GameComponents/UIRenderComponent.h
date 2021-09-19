#pragma once

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"

namespace Game {
    class UIRenderComponent : public GameEngine::TextRenderComponent {
    public:
        void setScreenPosition(sf::RenderWindow *window, sf::Transformable &transformable, sf::Vector2i vec) {
            transformable.setPosition(window->mapPixelToCoords(vec));
            float scale = window->getView().getSize().x / window->getSize().x;
            transformable.setScale(scale, scale);
        }
        void centerText(sf::RenderWindow *window, sf::Text &text, sf::Vector2i offset) {
            sf::FloatRect rect = text.getLocalBounds();
            setScreenPosition(window, text, sf::Vector2i((window->getSize().x - rect.width) / 2, (window->getSize().y - rect.height) / 2) + offset);
        }
        UIRenderComponent() {
            bar.setFillColor(sf::Color(0xffaa00c0));
            fade.setFillColor(sf::Color(0x00000000));
        }
        void Render(sf::RenderTarget* target) override {
            sf::RenderWindow *window = GameEngine::GameEngineMain::GetInstance()->GetRenderWindow();
            sf::Vector2u windowSize = window->getSize();
            sf::Vector2f windowSizeF = sf::Vector2f(windowSize.x, windowSize.y);

            if(displayState == 1) {
                clrTarget = 0xc0;
                clrClr = 0x00000000;
            } else if(displayState == 2) {
                clrTarget = 0xe0;
                clrClr = 0x00500000;
            } else {
                clrTarget = 0;
            }

            if(displayState == 0) {
                setScreenPosition(window, m_text, sf::Vector2i(80, 50));
                m_text.setString(title);
                m_text.setFillColor(sf::Color(0x000000c0));
                target->draw(m_text);

                setScreenPosition(window, bar, sf::Vector2i(0, 0));
                bar.setSize(sf::Vector2f(timerPct * windowSize.x, 30));
                target->draw(bar);
            }

            setScreenPosition(window, fade, sf::Vector2i(0, 0));
            clr += (clrTarget - clr) / 10.0;
            fade.setFillColor(sf::Color(clrClr | ((int) clr)));
            fade.setSize(windowSizeF);
            target->draw(fade);

            if(displayState == 1 || displayState == 2) {
                m_text.setString(title);
                m_text.setCharacterSize(40);
                centerText(window, m_text, sf::Vector2i(0, -25));
                m_text.setFillColor(sf::Color(0xffffffff));
                target->draw(m_text);

                m_text.setString(subtitle);
                m_text.setCharacterSize(20);
                centerText(window, m_text, sf::Vector2i(0, 25));
                m_text.setFillColor(sf::Color(0xffffffff));
                target->draw(m_text);
            }
        }
        std::string title;
        std::string subtitle;
        float timerPct = 0;
        sf::RectangleShape bar;
        sf::RectangleShape fade;
        int displayState = 0;
        float clr = 0;
        float clrTarget = 0;
        int clrClr = 0;
    };
}