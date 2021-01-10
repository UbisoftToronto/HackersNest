#pragma once

#include "GameEngine/EntitySystem/Component.h"

namespace Game
{
    class HandPlayerMovementComponent : public GameEngine::Component
    {
    public:
        virtual void Update() override;
        virtual void OnAddToWorld() override;
    };
}