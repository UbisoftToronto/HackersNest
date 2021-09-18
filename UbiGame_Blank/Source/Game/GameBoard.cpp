#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"
#include "Game/GameEntities/PlayerEntity.h"
#include "Game/GameEntities/PlatformEntity.h"
#include "Game/GameComponents/PlayerMovementComponent.h"
#include "Game/GameComponents/ProjectileComponent.h"
#include "Game/GameComponents/ProjectileSpawnerComponent.h"

using namespace Game;

GameBoard::GameBoard()
    : m_player(nullptr)
{
  CreatePlayer();
  CreateBackground();
  CreatePlatform();
  //CreateProjectileSpawner();
  //CreateTestProjectile();
}

void GameBoard::CreatePlayer()
{
  m_player = new PlayerEntity();

  GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);
  m_player->SetPos(sf::Vector2f(60.f, 60.f));
  m_player->SetSize(sf::Vector2f(100.f, 100.f));

  //Movement
  m_player->AddComponent<Game::PlayerMovementComponent>();
  m_player->AddComponent<GameEngine::CollidablePhysicsComponent>();
  m_player->AddComponent<Game::ProjectileSpawnerComponent>();
}

void GameBoard::CreateBackground()
{
  GameEngine::Entity *bgEntity = new GameEngine::Entity();
  GameEngine::SpriteRenderComponent *render = bgEntity->AddComponent<GameEngine::SpriteRenderComponent>();
  render->SetTexture(GameEngine::eTexture::BG);
  render->SetZLevel(0);
  bgEntity->SetPos(sf::Vector2f(250.f, 250.f));
  bgEntity->SetSize(sf::Vector2f(500.f, 500.f));
  GameEngine::GameEngineMain::GetInstance()->AddEntity(bgEntity);

  m_backGround = bgEntity;
}

void GameBoard::CreatePlatform()
{
  PlatformEntity *platform = new PlatformEntity();
  GameEngine::GameEngineMain::GetInstance()->AddEntity(platform);
  platform->SetPos(sf::Vector2f(200.f, 200.f));
  platform->SetSize(sf::Vector2f(150.f, 50.f));

  platform->AddComponent<GameEngine::CollidableComponent>();
}

void GameBoard::CreateTestProjectile()
{
  GameEngine::Entity *projectile = new GameEngine::Entity();
  GameEngine::GameEngineMain::GetInstance()->AddEntity(projectile);

  projectile->SetPos(sf::Vector2f(50.f, 50.f));
  projectile->SetSize(sf::Vector2f(28.f, 17.f));

  GameEngine::SpriteRenderComponent *render = static_cast<GameEngine::SpriteRenderComponent *>(projectile->AddComponent<GameEngine::SpriteRenderComponent>());

  render->SetTexture(GameEngine::eTexture::Projectile);
  render->SetFillColor(sf::Color::Transparent);
  render->SetZLevel(2);

  ProjectileComponent *projectileComponent = static_cast<ProjectileComponent *>(projectile->AddComponent<ProjectileComponent>());
  projectileComponent->SetVelocity(sf::Vector2f(50.f, 0.f));
  projectileComponent->SetLifeTime(3.f);

  projectile->AddComponent<ProjectileComponent>();
}

GameBoard::~GameBoard()
{
}

void GameBoard::Update()
{
}
