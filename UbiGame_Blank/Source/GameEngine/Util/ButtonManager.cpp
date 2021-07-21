#include "ButtonManager.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/ButtonComponent.h"

#include <assert.h>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/View.hpp>

using namespace GameEngine;

ButtonManager* ButtonManager::sm_instance = nullptr;


ButtonManager::ButtonManager()
{

}


ButtonManager::~ButtonManager()
{

}


void ButtonManager::RegisterButton(ButtonComponent* button)
{
    auto found = std::find(m_buttons.begin(), m_buttons.end(), button);
    assert(found == m_buttons.end()); //Drop an assert if we add duplicate;
    if (found == m_buttons.end())
    {
        m_buttons.push_back(button);
    }
}


void ButtonManager::UnRegisterButton(ButtonComponent* button)
{
    auto found = std::find(m_buttons.begin(), m_buttons.end(), button);
    assert(found != m_buttons.end()); //Drop an assert if we remove a non existing entity;
    if (found != m_buttons.end())
    {
        m_buttons.erase(found);
    }
}


void ButtonManager::OnMouseButtonPressedEvent(int mouseX, int mouseY) const
{
    if (m_buttons.empty())
    {
        return;
    }
    
    const sf::Vector2f worldPoint = GameEngineMain::GetInstance()->GetRenderTarget()->mapPixelToCoords(sf::Vector2i(mouseX, mouseY));

    for (ButtonComponent* button : m_buttons)
    {
        if (button->GetWorldAABB().contains(worldPoint))
        {
            button->OnButtonClicked();
        }
    }
}
