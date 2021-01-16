#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "../PlayerMovementComponent.h"



using namespace Game;

void GameBoard::CreatePlayer()
{
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);
	
	m_player->SetPos(sf::Vector2f(150.0f, 150.0f));  // <-- Move its initial position
	m_player->SetSize(sf::Vector2f(50.0f, 50.0f)); // <-- Make the square bigger

	m_player->AddComponent<Game::PlayerMovementComponent>();  // <-- Added the movement component to the player
}


GameBoard::GameBoard()
{
	CreatePlayer();
	CreateBackground();
}


    GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
    (m_player->AddComponent<GameEngine::SpriteRenderComponent>());

    spriteRender->SetFillColor(sf::Color::Red);
    spriteRender->SetTexture(GameEngine::eTexture::Pudge);
}

void GameBoard::CreateBackground() {
    GameEngine::Entity* background = new GameEngine::Entity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(background);

    background->SetPos(sf::Vector2f(250.f, 250.f));
    background->SetSize(sf::Vector2f(800.f, 600.f));

    GameEngine::SpriteRenderComponent* render = static_cast<GameEngine::SpriteRenderComponent*>
    (background->AddComponent<GameEngine::SpriteRenderComponent>());

	m_player->AddComponent<Game::PlayerMovementComponent>();  // <-- Added the movement component to the player
    render->SetTexture(GameEngine::eTexture::Background);
    render->SetFillColor(sf::Color::Transparent);
}

GameBoard::GameBoard()
{
	CreatePlayer();
    //CreateBackground();
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}

