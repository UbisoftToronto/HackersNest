#include "PaddleEntity.h"
#include "Game/Paddle/Paddlemovement.h"
#include <GameEngine/EntitySystem/Components/SpriteRenderComponent.h>



using namespace Game;



PaddleEntity::PaddleEntity() 
{
	paddleMovement = AddComponent<Paddlemovement>();
	
	
	//movement

	
	
}
PaddleEntity::~PaddleEntity()
{

}


