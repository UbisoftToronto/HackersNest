#pragma once

#include <vector>

namespace GameEngine
{
    class ButtonComponent;

    class ButtonManager
    {
    public:
        ~ButtonManager();

        static ButtonManager* GetInstance() { if (!sm_instance) sm_instance = new ButtonManager(); return sm_instance; }

        void RegisterButton(ButtonComponent* button);
        void UnRegisterButton(ButtonComponent* button);

        void OnMouseButtonPressedEvent(int mouseX, int mouseY) const;
    private:
        ButtonManager();
        static ButtonManager* sm_instance;

        std::vector<ButtonComponent*> m_buttons;
    };
}
