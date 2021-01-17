#pragma once
#include <stdlib.h>
#include "../Component.h"

namespace Game
{
    class EnemyMovementComponent : public GameEngine::Component
    {
        float destination_x = 100;
        float destination_y = 100;
        float timer = 1;
    public:
        virtual void Update() override;
        virtual void OnAddToWorld() override;
        GameEngine::Entity* player = nullptr;
        
    };
}