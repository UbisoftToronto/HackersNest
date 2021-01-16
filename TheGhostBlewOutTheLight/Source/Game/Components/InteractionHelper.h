#pragma once

#include "GameEngine/EntitySystem/Component.h"

namespace Interaction
{
    class InteractionHelper : public GameEngine::Component
    {
    public:
        InteractionHelper();
        ~InteractionHelper();
        virtual void Update() override;
        virtual void OnAddToWorld() override;
        virtual void Consequence();
        virtual void CollisionDialog();
        virtual void InteractiveNoise();
    };
}