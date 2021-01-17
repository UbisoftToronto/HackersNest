#include "BallCollideComponent.h"

#include "GameEngine/Util/CollisionManager.h"
#include "GameEngine/EntitySystem/Entity.h"
#include "Game/Ball/BallComponents/BallMovementComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

#include <vector>

using namespace GameEngine;

BallCollideComponent::BallCollideComponent()
{

}


BallCollideComponent::~BallCollideComponent()
{

}


void BallCollideComponent::OnAddToWorld()
{
	CollidablePhysicsComponent::OnAddToWorld();
}


void BallCollideComponent::OnRemoveFromWorld()
{
	CollidablePhysicsComponent::OnRemoveFromWorld();
}


void BallCollideComponent::Update()
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
		// colliding with colComponent
		AABBRect colideBox = colComponent->GetWorldAABB();
		if (myBox.intersects(colideBox, intersection))
		{
			Game::BallMovementComponent* ballMove = GetEntity()->GetComponent<Game::BallMovementComponent>();
			SpriteRenderComponent* ballColor = GetEntity()->GetComponent<SpriteRenderComponent>();

			if (colComponent->GetEntity()->flag == 2) {
				if (/*check to make sure its in front*/true) {
					ballColor->SetTexture(GameEngine::eTexture::LeftBall);
					ballColor->UpdateSpriteParams();
				}
			}
			else if (colComponent->GetEntity()->flag == 3) {
				if (/*Check to make sure its in front*/true) {
					ballColor->SetTexture(GameEngine::eTexture::RightBall);
					ballColor->UpdateSpriteParams();
				}
			}

			sf::Vector2f pos = GetEntity()->GetPos();
			if (intersection.width < intersection.height)
			{
				if (ballMove->GetXDirection() > 0)
					pos.x -= intersection.width;
				else
					pos.x += intersection.width;
				
				ballMove->SetXDirection(-ballMove->GetXDirection());
			}
			else
			{
				if (ballMove->GetYDirection() > 0)
					pos.y -= intersection.height;
				else
					pos.y += intersection.height;

				ballMove->SetYDirection(-ballMove->GetYDirection());
			}
			GetEntity()->SetPos(pos);
		}
	}
}