#include "Paddlemovement.h"
#include "GameEngine/GameEngineMain.h"

#include <SFML/Window/Keyboard.hpp>

using namespace Game;

Paddlemovement::Paddlemovement()
{

}

Paddlemovement::~Paddlemovement()
{

}


void Paddlemovement::OnAddToWorld()
{
	__super::OnAddToWorld();
}

void Paddlemovement::Update()
//Add keyboard movements
{
	__super::Update();

	//return time between time updated frame
	float dt = GameEngine::GameEngineMain::GetTimeDelta();

	sf::Vector2f wantedVel = sf::Vector2f(0.f, 0.f);

	float playerVel = 100.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		wantedVel.y += playerVel * dt;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		wantedVel.y -= playerVel * dt;
	}

	GetEntity()->SetPos(GetEntity()->GetPos() + wantedVel);
} 