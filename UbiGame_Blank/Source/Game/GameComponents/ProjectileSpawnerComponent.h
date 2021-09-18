
#include "GameEngine/EntitySystem/Component.h"

namespace Game
{
    class ProjectileSpawnerComponent : public GameEngine::Component
    {
    public:
        ProjectileSpawnerComponent();
        ~ProjectileSpawnerComponent();

        virtual void Update() override;
        void SpawnProjectile();

    private:
        bool m_wasFirePressed;
    };
}