#include "GameEngine/GameEngineMain.h"

int main()
{
	GameEngine::GameEngineMain* mainEngine = GameEngine::GameEngineMain::GetInstance();

	mainEngine->GetRenderWindow()->setTitle("Covid Game");
	mainEngine->GetRenderWindow()->setSize(sf::Vector2u(1600, 1600));
	mainEngine->GetRenderWindow()->setFramerateLimit(60);

	while (mainEngine->GetRenderWindow()->isOpen())
	{				
		mainEngine->Update();
	}

	delete mainEngine;
	return 0;
}