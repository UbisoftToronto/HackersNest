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
			if (colComponent->GetEntity()->flag == 0) {
				ballMove->SetXDirection(-ballMove->GetXDirection());
			}
			else if (colComponent->GetEntity()->flag == 1) {
				ballMove->SetYDirection(-ballMove->GetYDirection());
			}
			else if (colComponent->GetEntity()->flag == 2) {
				ballMove->SetXDirection(-ballMove->GetXDirection());
				//if (/*check to make sure its in front*/true) {
				//	// Red
				//	ballColor->SetTexture(GameEngine::eTexture::LeftBall);
				//}
			}
			else if (colComponent->GetEntity()->flag == 3) {
				ballMove->SetXDirection(-ballMove->GetXDirection());
				ballColor->SetTexture(GameEngine::eTexture::RightBall);
				//if (/*Check to make sure its in front*/true) {
				//	// Blue
				//	ballColor->SetTexture(GameEngine::eTexture::RightBall);
				//}
			}
			else {
				ballMove->SetXDirection(-ballMove->GetXDirection());
				ballMove->SetYDirection(-ballMove->GetYDirection());
			}
		}
	}
}