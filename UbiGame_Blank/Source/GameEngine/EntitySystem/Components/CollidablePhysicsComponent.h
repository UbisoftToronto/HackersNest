#pragma once
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"

namespace GameEngine
{
	//This one allows for movement and obstacle detection, 
	class CollidablePhysicsComponent : public CollidableComponent
	{
	public:
		CollidablePhysicsComponent();
		virtual ~CollidablePhysicsComponent();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

		virtual void Update() override;
	};

    class GravityPhysicsComponent : public GameEngine::CollidablePhysicsComponent
    {
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

