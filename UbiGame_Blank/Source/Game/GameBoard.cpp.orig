#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "../PlayerMovementComponent.h"



using namespace Game;

GameBoard::GameBoard()
{
	CreatePlayer();
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}

<<<<<<< HEAD
void GameBoard::CreatePlayer()
{
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);
	
	m_player->SetPos(sf::Vector2f(150.0f, 150.0f));  // <-- Move its initial position
	m_player->SetSize(sf::Vector2f(50.0f, 50.0f)); // <-- Make the square bigger

	GameEngine::RenderComponent* render = m_player->AddComponent<GameEngine::RenderComponent>(); // <-- Capturing the new component

	render->SetFillColor(sf::Color::Red); // <-- Change the fill color to Red
	m_player->AddComponent<Game::PlayerMovementComponent>();  // <-- Added the movement component to the player
=======
void GameBoard::CreateBackground() {
    GameEngine::Entity* background = new GameEngine::Entity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(background);

    background->SetPos(sf::Vector2f(250.f, 250.f));
    background->SetSize(sf::Vector2f(800.f, 600.f));

    GameEngine::SpriteRenderComponent* render = static_cast<GameEngine::SpriteRenderComponent*>
    (background->AddComponent<GameEngine::SpriteRenderComponent>());

    render->SetTexture(GameEngine::eTexture::Background);
    render->SetFillColor(sf::Color::Transparent);
>>>>>>> 6c4d65dfa7fdcaacc9e550b8f1be246fa701cfec
}