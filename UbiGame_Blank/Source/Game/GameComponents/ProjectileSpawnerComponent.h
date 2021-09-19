
#include "GameEngine/EntitySystem/Component.h"
#include <SFML/System/Vector2.hpp>

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
        sf::Vector2f direction;
        bool m_wasFirePressed;
    };
}