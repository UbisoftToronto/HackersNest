#pragma once

#include "UbiGame_Blank\Source\GameEngine\GameEngineMain.h"

namespace Game
{
    class PlayerMovementComponent : public GameEngine::Component
    {
        float destination_x = 500.f;
        float destination_y = 500.f;
    public:
        virtual void Update() override;
        virtual void OnAddToWorld() override;
    };
}