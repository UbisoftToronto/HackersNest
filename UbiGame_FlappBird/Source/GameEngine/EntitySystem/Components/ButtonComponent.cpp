#include "ButtonComponent.h"

#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/Util/ButtonManager.h"

#include "GameEngine/GameEngineMain.h"

using namespace GameEngine;

ButtonComponent::ButtonComponent()
    : m_useDefaultBox(true)
{

}


ButtonComponent::~ButtonComponent()
{

}


void ButtonComponent::OnAddToWorld()
{
    Component::OnAddToWorld();
    ButtonManager::GetInstance()->RegisterButton(this);

    if (m_useDefaultBox)
        SetupDefaultBoundingBox();
}


void ButtonComponent::OnRemoveFromWorld()
{
    Component::OnRemoveFromWorld();

    ButtonManager::GetInstance()->UnRegisterButton(this);
}


void ButtonComponent::SetupDefaultBoundingBox()
{
    //Static AABB for the time being		
    SetBoundingBox(GetEntity()->GetSize());
}


void ButtonComponent::SetBoundingBox(sf::Vector2f size)
{
    m_AABBBox.width = size.x;
    m_AABBBox.height = size.y;

    m_AABBBox.left = -m_AABBBox.width / 2.f;
    m_AABBBox.top = -m_AABBBox.height / 2.f;

    m_useDefaultBox = false;
}


const AABBRect ButtonComponent::GetWorldAABB() const
{
    AABBRect box = m_AABBBox;

    box.left += GetEntity()->GetPos().x;
    box.top += GetEntity()->GetPos().y;

    return box;
}


void ButtonComponent::OnButtonClicked()
{
}