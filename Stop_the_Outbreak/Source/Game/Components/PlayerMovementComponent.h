#pragma once

#include "GameEngine/EntitySystem/Component.h"

namespace Game
{
    class PlayerMovementComponent : public GameEngine::Component
    {
    public:
        virtual void Update() override;
        virtual void OnAddToWorld() override;
    };
}