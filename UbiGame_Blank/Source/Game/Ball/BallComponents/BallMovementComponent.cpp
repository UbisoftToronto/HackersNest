#include "BallMovementComponent.h"

#include "GameEngine/GameEngineMain.h"
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace Game;

BallMovementComponent::BallMovementComponent()
	: xDirection(0.f), yDirection(0.f), speed(0.f)
{

}

BallMovementComponent::~BallMovementComponent() 
{

}

void BallMovementComponent::OnAddToWorld()
{
	__super::OnAddToWorld();
	srand(time(0));
	speed = 200.f;
	xDirection = 90 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 110));

	int randBit = rand() % 2;

	if (randBit) {
		xDirection *= -1;
	}

	yDirection = sqrt(pow(speed, 2) - pow(xDirection, 2));
	int negBit = rand() % 2;
	if (negBit) {
		yDirection *= -1;
	}
}

void BallMovementComponent::Update() 
{
	//__super::Update();
	Component::Update();
	float dt = GameEngine::GameEngineMain::GetTimeDelta();
	sf::Vector2f direction = sf::Vector2f(xDirection * dt, yDirection * dt);
	GetEntity()->SetPos(GetEntity()->GetPos() + direction);

}