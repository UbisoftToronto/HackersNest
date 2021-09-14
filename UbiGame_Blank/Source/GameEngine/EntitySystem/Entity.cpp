#include "Entity.h"

#include <assert.h>

#include "GameEngine/GameEngineMain.h"

using namespace GameEngine;

Entity::Entity()
    : m_pos(0.f, 0.f)
    , m_size(0.f, 0.f)
    , m_rotation(0.f)
    , m_parent(nullptr)
{

}

Entity::~Entity()
{
    DestroyComponents();
}


void Entity::OnAddToWorld()
{
    for (auto component : m_components)
    {
        component->OnAddToWorld();
    }
}


void Entity::OnRemoveFromWorld()
{
    for (auto component : m_components)
    {
        component->OnRemoveFromWorld();
    }

    ClearChildren();
    if (m_parent != nullptr)
    {
        m_parent->RemoveChild(this);
    }

    ClearEntityTag();
}


void Entity::SetEntityTag(std::string tag)
{
    if (m_entityTag.has_value())
    {
        ClearEntityTag();
    }

    m_entityTag = tag;
    GameEngineMain::GetInstance()->RefreshEntityTag(this);
}


void Entity::ClearEntityTag()
{
    if (m_entityTag.has_value())
    {
        GameEngineMain::GetInstance()->RemoveEntityTagFromMap(this, m_entityTag.value());
        m_entityTag.reset();
    }
}

std::string Entity::GetEntityTag() const
{
    if (m_entityTag.has_value())
    {
        return m_entityTag.value();
    }
    return "";
}

bool Entity::HasEntityTag() const
{
    return m_entityTag.has_value();
}


void Entity::DestroyComponents()
{
    for (auto component : m_components)
    {
        delete component;
    }

    m_components.clear();
}


void Entity::Update()
{
    for (auto component : m_components)
    {
        component->Update();
    }
}

sf::Vector2f Entity::GetPos() const
{
    if (m_parent == nullptr)
    {
        return m_pos;
    }

    return m_parent->GetPos() + m_localPosOffset;
}

sf::Vector2f Entity::GetSize() const
{
    if (m_parent == nullptr)
    {
        return m_size;
    }
    sf::Vector2f parentSize = m_parent->GetSize();
    return sf::Vector2f(parentSize.x * m_size.x, parentSize.y * m_size.y);
}

float Entity::GetRot() const
{
    if (m_parent == nullptr)
    {
        return m_rotation;
    }

    return m_parent->GetRot() + m_localRotOffset;
}

void Entity::SetPos(sf::Vector2f pos)
{
    assert(m_parent == nullptr); //Assert if we are trying to set the world position of an entity that is parented to another entity. Use SetLocalPosOffset instead!

    m_pos = pos;
}

void Entity::SetParent(Entity* entity, bool retainWorldPos /*= false*/)
{
    assert(entity != nullptr); //Assert if trying to set parent as nullptr, use RemoveParent instead!

    if (m_parent != nullptr)
    {
        RemoveParent();
    }
    m_parent = entity;
    if (m_parent != nullptr)
    {
        m_parent->AddChild(this);
        if (retainWorldPos)
        {
            m_localPosOffset = m_pos - m_parent->GetPos();
        }
        else
        {
            m_localPosOffset = sf::Vector2f(0.f, 0.f);
        }
    }
}

void Entity::RemoveParent()
{
    // Set Pos to current world position before removing the parent
    m_pos = GetPos();
    m_localPosOffset = sf::Vector2f(0.f, 0.f);
    m_parent = nullptr;
}

void Entity::AddChild(Entity* entity)
{
    auto it = std::find(m_children.cbegin(), m_children.cend(), entity);
    if (it == m_children.cend())
    {
        m_children.push_back(entity);
    }
}

void Entity::RemoveChild(Entity* entity)
{
    for (auto it = m_children.begin(); it != m_children.end();)
    {
        Entity* child = (*it);
        if (child != nullptr && child == entity)
        {
            it = m_children.erase(it);
            child->RemoveParent();
        }
        else
        {
            ++it;
        }
    }
}

void Entity::ClearChildren()
{
    for (auto it = m_children.begin(); it != m_children.end();)
    {
        Entity* child = (*it);
        if (child != nullptr)
        {
            it = m_children.erase(it);
            child->RemoveParent();
        }
        else
        {
            ++it;
        }
    }
}