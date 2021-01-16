#pragma once
#include "GameEngine/EntitySystem/Component.h"
#include <SFML/Window/Keyboard.hpp>


namespace Game
{
class PlayerMovementComponent : public GameEngine::Component
    {
    public:
        virtual void Update() override;
        virtual void OnAddToWorld() override;

        void setPlayerControls(int playerControls[4]);

    private:
        int controls[4];  //0 and 1 for left right. 2 and 3 for up and down.
    };
}