#include "CollidablePhysicsComponent.h"

#include "GameEngine/Util/CollisionManager.h"
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/GameEngineMain.h"

#include <vector>

using namespace GameEngine;

CollidablePhysicsComponent::CollidablePhysicsComponent()
	: m_didCollide(false), m_lastCollideEntity(nullptr)
{
}

CollidablePhysicsComponent::~CollidablePhysicsComponent()
{
}

void CollidablePhysicsComponent::OnAddToWorld()
{
	CollidableComponent::OnAddToWorld();
}

void CollidablePhysicsComponent::OnRemoveFromWorld()
{
	CollidableComponent::OnRemoveFromWorld();
}

void CollidablePhysicsComponent::Update()
{
	//For the time being just a simple intersection check that moves the entity out of all potential intersect boxes
	std::vector<CollidableComponent *> &collidables = CollisionManager::GetInstance()->GetCollidables();
	m_didCollide = false;
	m_lastCollideEntity = nullptr;

	for (int a = 0; a < collidables.size(); ++a)
	{
		CollidableComponent *colComponent = collidables[a];
		if (colComponent == this)
			continue;

		AABBRect intersection;
		AABBRect myBox = GetWorldAABB();
		AABBRect colideBox = colComponent->GetWorldAABB();
		if (myBox.intersects(colideBox, intersection))
		{
			sf::Vector2f pos = GetEntity()->GetPos();
			if (intersection.width < intersection.height)
			{
				if (myBox.left < colideBox.left)
					pos.x -= intersection.width;
				else
					pos.x += intersection.width;
			}
			else
			{
				if (myBox.top < colideBox.top)
					pos.y -= intersection.height;
				else
					pos.y += intersection.height;
			}

			if (colComponent->GetEntity()->GetEntityType() == EEntityType::Platform ||
				(GetEntity()->GetEntityType() == EEntityType::Projectile && colComponent->GetEntity()->GetEntityType() == EEntityType::Virus))
			{
				m_didCollide = true;
				m_lastCollideEntity = colComponent->GetEntity();
				GetEntity()->SetPos(pos);
			}
		}
	}
}
