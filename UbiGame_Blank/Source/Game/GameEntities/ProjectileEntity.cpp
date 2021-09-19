#include "ProjectileEntity.h"
#include <SFML/System/Vector2.hpp>
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "GameEngine/EntitySystem/Components/ParticleEmitterComponent.h"
#include "GameEngine/EntitySystem/Components/SoundComponent.h"

using namespace Game;

ProjectileEntity::ProjectileEntity()
{
    //m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
    //m_renderComponent->SetTexture(GameEngine::eTexture::Projectile);
    //m_renderComponent->SetZLevel(2);
}

ProjectileEntity::~ProjectileEntity()
{
}

void ProjectileEntity::OnAddToWorld()
{
    Entity::OnAddToWorld();
}

void ProjectileEntity::OnRemoveFromWorld()
{
    Entity::OnRemoveFromWorld();
}