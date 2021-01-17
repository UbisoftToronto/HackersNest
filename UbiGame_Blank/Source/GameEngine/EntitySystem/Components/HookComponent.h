#pragma once

#include "../Component.h"

namespace Game
{
    class HookComponent : public GameEngine::Component
    {
    public:
        float destination_x=0.f, destination_y=0.f;
        float liveTime;
        float retractTime;
        bool retracting = false;
        virtual void Update() override;
        virtual void OnAddToWorld() override;
    };
}