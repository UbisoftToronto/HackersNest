#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"



using namespace Game;

GameBoard::GameBoard()
{

}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}

void GameBoard::CreateBackground() {
    GameEngine::Entity* background = new GameEngine::Entity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(background);

    background->SetPos(sf::Vector2f(250.f, 250.f));
    background->SetSize(sf::Vector2f(800.f, 600.f));

    GameEngine::SpriteRenderComponent* render = static_cast<GameEngine::SpriteRenderComponent*>
    (background->AddComponent<GameEngine::SpriteRenderComponent>());

    render->SetTexture(GameEngine::eTexture::Background);
    render->SetFillColor(sf::Color::Transparent);
}