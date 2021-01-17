#include "CollidablePhysicsComponent.h"

#include "GameEngine/Util/CollisionManager.h"
#include "GameEngine/EntitySystem/Entity.h"

#include <vector>

using namespace GameEngine;

CollidablePhysicsComponent::CollidablePhysicsComponent()
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
	std::vector<CollidableComponent*>& collidables = CollisionManager::GetInstance()->GetCollidables();

	for (int a = 0; a < collidables.size(); ++a)
	{
		CollidableComponent* colComponent = collidables[a];
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
			if ((colComponent->type =="wall" || colComponent->type =="river") && type=="pudge")
				GetEntity()->SetPos(pos);
			else if (colComponent->type =="pudge" && (colComponent->type =="wall" || colComponent->type =="river"))
				GetEntity()->SetPos(pos);
			
			else
				sort_collision(colComponent->type);
		
		}
	}
}

void sort_collision(std::string type1) 
{
	//if (type1 == "pongball" && type =="wall")
		//insert app. call here;
	//else if (type1 == "wall" && type =="pongball")
		//insert app. call here

	//else if (type1 == "pudge" && type =="hook")
		//insert app. call here
	//else if (type1 == "hook" && type =="pudge")
		//insert app. call here

	//else if (type1 == "hook" && type =="pongball")
		//insert app. call here	
	//else if (type1 == "pongball" && type =="hook")
		//insert app. call here	

	//else if (type1 == "pudge" && type =="pongball")
		//insert app. call here	
	//else if (type1 == "pongball" && type =="pudge")
		//insert app. call here	


				
}