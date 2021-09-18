#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

namespace Game
{
    class PlatformEntity : public GameEngine::Entity
    {
    public:
        PlatformEntity();
        ~PlatformEntity();

        virtual void OnAddToWorld() override;
        virtual void OnRemoveFromWorld() override;

    protected:
        GameEngine::SpriteRenderComponent* m_renderComponent;
    };
}
