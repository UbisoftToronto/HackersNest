#include "ProjectileComponent.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Component.h"
#include "GameEngine/Util/CollisionManager.h"

using namespace Game;

ProjectileComponent::ProjectileComponent()
    : frameLifeTime(10.f), m_velocity(sf::Vector2f(0.f, 0.f))
{
}

ProjectileComponent::~ProjectileComponent()
{
}

void ProjectileComponent::OnAddToWorld()
{
  //CollidableComponent::OnAddToWorld();
}

void ProjectileComponent::Update()
{
    Component::Update();

    float dt = GameEngine::GameEngineMain::GetTimeDelta();
    // reduce lifetime every frame
    frameLifeTime -= dt;

    sf::Vector2f wantedVel = m_velocity * dt;
    GetEntity()->SetPos(GetEntity()->GetPos() + wantedVel);

    UpdateProjectileHit();

    // if below 0, projectile is dead, ask engine to remove it
    if (frameLifeTime < 0.f)
    {
        //GameEngine::GameEngineMain::GetInstance()->RemoveEntity(GetEntity());
        GetEntity()->SetPos(sf::Vector2f(10000.f, 10000.f));
    }
}

void ProjectileComponent::UpdateProjectileHit()
{
    GameEngine::CollidablePhysicsComponent *colPhys = GetEntity()->GetComponent<GameEngine::CollidablePhysicsComponent>();
    if (!colPhys)
    {
        return;
    }

    if (colPhys->DidCollide() && colPhys->GetLastCollideEntity() != nullptr)
    {
        //GameEngine::GameEngineMain::GetInstance()->RemoveEntity(GetEntity());
        GetEntity()->SetPos(sf::Vector2f(10000.f, 10000.f));

        if (colPhys->GetLastCollideEntity()->GetEntityType() == GameEngine::EEntityType::Virus)
        {
            //GameEngine::GameEngineMain::GetInstance()->RemoveEntity(colPhys->GetLastCollideEntity());
            colPhys->GetLastCollideEntity()->SetPos(sf::Vector2f(10000.f, 10000.f));
        }
    }
}
