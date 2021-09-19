#include "ProjectileSpawnerComponent.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Component.h"
#include "GameEngine/Util/CollisionManager.h"
#include "ProjectileComponent.h"
#include "Game/GameEntities/ProjectileEntity.h"

#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"

Game::ProjectileSpawnerComponent::ProjectileSpawnerComponent()
    : m_wasFirePressed(false), direction(sf::Vector2f(500.f, 0.f))
{
}

Game::ProjectileSpawnerComponent::~ProjectileSpawnerComponent()
{
}

void Game::ProjectileSpawnerComponent::Update()
{
    Component::Update();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        m_wasFirePressed = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        direction.x = 500.f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        direction.x = -500.f;
    }
    else
    {
        if (m_wasFirePressed)
        {
            SpawnProjectile();
        }

        m_wasFirePressed = false;
    }
}

void Game::ProjectileSpawnerComponent::SpawnProjectile()
{
    ProjectileEntity *projectile = new ProjectileEntity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(projectile);

    projectile->SetEntityType(GameEngine::EEntityType::Projectile);

    // displacement for projectile spawn point: change the float value to adjust
    sf::Vector2f d(GetEntity()->GetPos().x + 65.f, GetEntity()->GetPos().y);

    if (direction.x < 0)
    {
        d.x = GetEntity()->GetPos().x - 65.f;
    }

    projectile->SetPos(d);
    projectile->SetSize(sf::Vector2f(28.f, 17.f));

    GameEngine::SpriteRenderComponent *render = static_cast<GameEngine::SpriteRenderComponent *>(projectile->AddComponent<GameEngine::SpriteRenderComponent>());

    render->SetTexture(GameEngine::eTexture::Projectile);
    render->SetFillColor(sf::Color::Transparent);
    render->SetZLevel(3);

    ProjectileComponent *projectileComponent = static_cast<ProjectileComponent *>(projectile->AddComponent<ProjectileComponent>());
    projectileComponent->SetVelocity(direction);
    projectileComponent->SetLifeTime(3.f);

    projectile->AddComponent<ProjectileComponent>();
    projectile->AddComponent<GameEngine::CollidablePhysicsComponent>();
}
