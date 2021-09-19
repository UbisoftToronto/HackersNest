#pragma once
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

namespace GameEngine
{
    class GravityPhysicsComponent : public GameEngine::CollidablePhysicsComponent
    {
        using base_type = GameEngine::CollidablePhysicsComponent;
    public:
        GravityPhysicsComponent();
        ~GravityPhysicsComponent();

        virtual void OnAddToWorld() override;
        virtual void Update() override;

        void SetVelocity(sf::Vector2f vel) { m_wantedVelocity = vel; }

    private:
        //Velocity that the object wants to have
        sf::Vector2f m_wantedVelocity;
        //Current velocity
        sf::Vector2f m_velocity;
        //Position of the object in the last frame
        sf::Vector2f m_lastPos;
    };
}

