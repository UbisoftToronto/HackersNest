#include "GameBoard.h"
#include "../GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "GameEngine/GameEngineMain.h"
#include "../GameEngine/EntitySystem/Components/PlayerMovementComponent.h"
#include "../GameEngine/EntitySystem/Components/PlayerAbilityComponent.h"


using namespace Game;

void GameBoard::CreatePlayer()
{
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);
	
	m_player->SetPos(sf::Vector2f(150.0f, 150.0f));  // <-- Move its initial position
	m_player->SetSize(sf::Vector2f(50.0f, 50.0f)); // <-- Make the square bigger

	m_player->AddComponent<Game::PlayerMovementComponent>();  // <-- Added the movement component to the player

    GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
    (m_player->AddComponent<GameEngine::SpriteRenderComponent>());

    spriteRender->SetTexture(GameEngine::eTexture::Player);

    m_player->AddComponent<Game::PlayerAbilityComponent>();
    //Adding CollidingPhysicsComponent to Player
    m_player->AddComponent<GameEngine::CollidablePhysicsComponent>();

}

void GameBoard::CreateBackground() {
    GameEngine::Entity* background = new GameEngine::Entity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(background);

    background->SetPos(sf::Vector2f(350.f, 350.f));
    background->SetSize(sf::Vector2f(700.f, 700.f));

    GameEngine::SpriteRenderComponent* render = static_cast<GameEngine::SpriteRenderComponent*>
    (background->AddComponent<GameEngine::SpriteRenderComponent>());
	m_player->AddComponent<Game::PlayerMovementComponent>();  // <-- Added the movement component to the player
    render->SetTexture(GameEngine::eTexture::Background);
    render->SetZLevel(-1);
    render->SetFillColor(sf::Color::Transparent);
}

GameBoard::GameBoard()
{
	CreatePlayer();
    CreateBackground();
    CreateObstacle(0,0,700,350,true); //window hitbox
    CreateObstacle(105,0,140,700,true); //River hitbox
    
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}

void GameBoard::CreateObstacle(float x_cord, float y_cord,float width, float height, bool hit_box) 
{
    //Create Obstacle Entity and add into game
    GameEngine::Entity* obstacle = new GameEngine::Entity();  
    GameEngine::GameEngineMain::GetInstance()->AddEntity(obstacle);

    

    //Define Obstacle
    obstacle->SetPos(sf::Vector2f(x_cord, y_cord)); 
    obstacle->SetSize(sf::Vector2f(width, height));
    
    if(!hit_box) //if not a hit box, its a pong ball. Give it a visual.
    {
        GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
        (obstacle->AddComponent<GameEngine::SpriteRenderComponent>());
        spriteRender->SetFillColor(sf::Color::Transparent);
        spriteRender->SetTexture(GameEngine::eTexture::PongBall);
    }

    obstacle->AddComponent<GameEngine::CollidableComponent>();

}

