#include "GravityPhysicsComponent.h"

#include "GameEngine/Util/CollisionManager.h"
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/GameEngineMain.h"

#include <vector>

using namespace GameEngine;

GravityPhysicsComponent::GravityPhysicsComponent()
{

}

GravityPhysicsComponent::~GravityPhysicsComponent()
{

}

float GravityPhysicsComponent::Lerp(float a, float b, float f)
{
    return (a * (1.0f - f)) + (b * f);
}

void GravityPhysicsComponent::Update()
{
    //Get DELTA time from the previous frame
    float dt = GameEngine::GameEngineMain::GetTimeDelta();
    //Log the current Y, before anything happens
    float currentY = GetEntity()->GetPos().y;

    //This is our gravitational acceleration
    float gAccel = 1000.f;

    if (dt > 0.f)
    {
        float lerpTime = 5.2f;
        //Set the current velocity as a lerp of the last one towards wanted
        m_velocity.x = Lerp(m_velocity.x, m_wantedVelocity.x, lerpTime * dt);
        m_velocity.y += m_wantedVelocity.y;

        //Accelerate Y of our velocity by gravity in time
        m_velocity.y += gAccel * dt;

        //V = Dx / Dt => Dx = V * Dt
        sf::Vector2f deltaVelocity = dt * m_velocity;
        GetEntity()->SetPos(GetEntity()->GetPos() + deltaVelocity);
    }

    base_type::Update();

    //Determine deltaY AFTER the collision update, so that it indicates actual distance travelled
    float deltaY = GetEntity()->GetPos().y - currentY;
    if (dt > 0.f)
    {
        //Our actual velocity is that position different in time:
        //m_velocity.y = deltaY / dt;
        if (m_velocity.y > 500)
        {
            m_velocity.y = 500;
        }
        else if (m_velocity.y < -500)
        {
            m_velocity.y = -500;
        }
    }
}

void GravityPhysicsComponent::OnAddToWorld()
{

}
