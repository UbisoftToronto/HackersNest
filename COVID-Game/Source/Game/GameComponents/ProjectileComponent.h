#pragma once

#include "GameEngine/EntitySystem/Component.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

namespace Game
{
    class ProjectileComponent : public GameEngine::CollidableComponent
    {
    public:
        ProjectileComponent();
        ~ProjectileComponent();

        virtual void Update() override;
        virtual void OnAddToWorld() override;

        void SetVelocity(sf::Vector2f vel) { m_velocity = vel; }
        void SetLifeTime(float frames) { frameLifeTime = frames; }
        void UpdateProjectileHit();
        //void SetDirection(int right) { direction = right; }

    private:
        sf::Vector2f m_velocity;
        float frameLifeTime;
        //bool direction; // Right is true, left is false
    };
}
