#include "PaddleEntity.h"
#include "Game/Paddle/Paddlemovement.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"



using namespace Game;



PaddleEntity::PaddleEntity() 
{
	paddleMovement = AddComponent<Paddlemovement>();
	collidableComponet = AddComponent<GameEngine::CollidableComponent>();
	//physicsComponet = AddComponent<GameEngine::CollidablePhysicsComponent>();
	
	//movement

	
	
}
PaddleEntity::~PaddleEntity()
{

}


