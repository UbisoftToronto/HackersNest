#pragma once

#include "GameEngine/EntitySystem/Component.h"

namespace Game
{
    class MousePressedComponent : public GameEngine::Component
    {
    public:
        virtual void Update() override;
        virtual void OnAddToWorld() override;
    };
}