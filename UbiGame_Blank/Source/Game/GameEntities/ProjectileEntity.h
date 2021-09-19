#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/AnimationComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

namespace Game
{

    class ProjectileEntity : public GameEngine::Entity
    {
    public:
        ProjectileEntity();
        ~ProjectileEntity();

        virtual void OnAddToWorld() override;
        virtual void OnRemoveFromWorld() override;
    };
}