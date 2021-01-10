#include "Entity.h"

using namespace GameEngine;

Entity::Entity()
	: m_pos(0.f, 0.f)
	, m_size(0.f, 0.f)	
	, m_rotation(0.f)
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





