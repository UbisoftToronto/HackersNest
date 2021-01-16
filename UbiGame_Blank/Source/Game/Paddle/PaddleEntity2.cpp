
#include "Game/Paddle/Paddlemovement2.h"
#include <GameEngine/EntitySystem/Components/SpriteRenderComponent.h>
#include <Game/Paddle/PaddleEntity2.h>



using namespace Game;



PaddleEntity2::PaddleEntity2()
{
	paddleMovement2 = AddComponent<Paddlemovement2>();


	//movement



}
PaddleEntity2::~PaddleEntity2()
{

}
