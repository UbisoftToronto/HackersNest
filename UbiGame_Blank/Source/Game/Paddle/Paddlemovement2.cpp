#include "Paddlemovement2.h"
#include "GameEngine/GameEngineMain.h"

#include <SFML/Window/Keyboard.hpp>
//Paddlemovement 2
using namespace Game;

Paddlemovement2::Paddlemovement2()
{

}

Paddlemovement2::~Paddlemovement2()
{

}


void Paddlemovement2::OnAddToWorld()
{
	__super::OnAddToWorld();
}

void Paddlemovement2::Update()
//Add keyboard movements
{
	__super::Update();

	//return time between time updated frame 

	float dt = GameEngine::GameEngineMain::GetTimeDelta();

	sf::Vector2f wantedVel = sf::Vector2f(0.f, 0.f);

	float playerVel = 100.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		wantedVel.y += playerVel * dt;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		wantedVel.y -= playerVel * dt;
	}

	GetEntity()->SetPos(GetEntity()->GetPos() + wantedVel);

}