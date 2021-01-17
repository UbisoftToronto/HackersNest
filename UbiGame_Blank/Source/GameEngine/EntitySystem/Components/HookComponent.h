#pragma once

#include "../Component.h"

namespace Game
{
    class HookComponent : public GameEngine::Component
    {
    public:
        float destination_x, destination_y;
        float liveTime;
        float retractTime;
        bool retracting = false;
        virtual void Update() override;
        virtual void OnAddToWorld() override;
    };
}