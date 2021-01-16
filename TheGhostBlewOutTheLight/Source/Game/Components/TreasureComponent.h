#pragma once

#include "InteractionHelper.h"

namespace Treasure
{
    class TreasureComponent : public Interaction::InteractionHelper
    {
    public:
        virtual void Update() override;
        virtual void OnAddToWorld() override;
        virtual void Consequence() override;
        virtual void CollisionDialog() override;
        virtual void InteractiveNoise() override;
    };
}