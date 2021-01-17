#include "GameBoard.h"
#include "../GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "GameEngine/GameEngineMain.h"
#include "../GameEngine/EntitySystem/Components/PlayerMovementComponent.h"
#include "../GameEngine/EntitySystem/Components/PlayerAbilityComponent.h"
#include "../GameEngine/EntitySystem/Components/EnemyMovementComponent.h"

using namespace Game;

void GameBoard::CreatePlayer()
{
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);
	
	m_player->SetPos(sf::Vector2f(150.0f, 150.0f));  // <-- Move its initial position
	m_player->SetSize(sf::Vector2f(64.0f, 64.0f)); // <-- Make the square bigger

	m_player->AddComponent<Game::PlayerMovementComponent>();  // <-- Added the movement component to the player

    GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
    (m_player->AddComponent<GameEngine::SpriteRenderComponent>());

    spriteRender->SetTexture(GameEngine::eTexture::Player);

    m_player->AddComponent<Game::PlayerAbilityComponent>();
    //Adding CollidingPhysicsComponent to Player
    GameEngine::CollidablePhysicsComponent* collisionTyper = static_cast<GameEngine::CollidablePhysicsComponent*>
        (m_player->AddComponent<GameEngine::CollidablePhysicsComponent>());
    collisionTyper->type="pudge";

}

void GameBoard::CreateEnemy(){
    m_enemy = new GameEngine::Entity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(m_enemy);
    m_enemy->SetPos(sf::Vector2f(550.0f, (float)(rand() % 600 + 50)));
    m_enemy->SetSize(sf::Vector2f(64.0f, 64.0f));

    Game::EnemyMovementComponent* enemyMovement = static_cast<Game::EnemyMovementComponent*>(m_enemy->AddComponent<Game::EnemyMovementComponent>());

    enemyMovement->player = m_player;

    GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>(m_enemy->AddComponent<GameEngine::SpriteRenderComponent>());

    spriteRender->SetTexture(GameEngine::eTexture::Player);

    GameEngine::CollidableComponent* collisionTyper = static_cast<GameEngine::CollidableComponent*>
        (m_enemy->AddComponent<GameEngine::CollidableComponent>());
    collisionTyper->type="pudge"; //give enemy pudge(s) collision type of "pudge"

    


   
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
    CreateEnemy();

    

    //ENVIRONMENTAL HITBOXES 
    CreateObstacle(0,350,50,700,"wall"); //left wall hitbox
    CreateObstacle(350,0,700,50,"wall"); //top wall hitbox
    CreateObstacle(700,350,50,700,"wall"); //right wall hitbox
    CreateObstacle(350,700,700,50,"wall"); //bottom wall hitbox
    CreateObstacle(350,350,145,700,"river"); //River hitbox
    
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}

void GameBoard::CreateObstacle(float x_cord, float y_cord,float width, float height, std::string object_type) 
//fn that makes pongballs, walls and rivers
{
    //Create Obstacle Entity and add into game
    GameEngine::Entity* obstacle = new GameEngine::Entity();  
    GameEngine::GameEngineMain::GetInstance()->AddEntity(obstacle);



    

    //Define Obstacle
    obstacle->SetPos(sf::Vector2f(x_cord, y_cord)); 
    obstacle->SetSize(sf::Vector2f(width, height));

    //Pointer To Identify Hitbox types AND add collider component
    GameEngine::CollidableComponent* collisionTyper = static_cast<GameEngine::CollidableComponent*>
    (obstacle->AddComponent<GameEngine::CollidableComponent>());
   
    
    if(object_type=="pongball") //if a pong ball. Give it a visual.
    {
        GameEngine::SpriteRenderComponent* spriteRender = static_cast<GameEngine::SpriteRenderComponent*>
        (obstacle->AddComponent<GameEngine::SpriteRenderComponent>());
        spriteRender->SetFillColor(sf::Color::Transparent);
        spriteRender->SetTexture(GameEngine::eTexture::PongBall);
        collisionTyper->type = "pongball"; //Give collisionComponent type: pongball
    } 
    else if (object_type=="river")
        collisionTyper->type = "river"; //if river, no collisions
                                           // Give collisionComponent type: river
    else
        collisionTyper->type = "wall"; //if wall, no collisions
                                           // Give collisionComponent type: wall


    

}

