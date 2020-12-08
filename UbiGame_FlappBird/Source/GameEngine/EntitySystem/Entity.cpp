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
	for each (auto component in m_components)
	{
		component->OnAddToWorld();
	}
}


void Entity::OnRemoveFromWorld()
{
	for each (auto component in m_components)
	{
		component->OnRemoveFromWorld();
	}
}


void Entity::DestroyComponents()
{
	for each (auto component in m_components)
	{
		delete component;
	}

	m_components.clear();
}


void Entity::Update()
{
	for each (auto component in m_components)
	{
		component->Update();
	}
}





