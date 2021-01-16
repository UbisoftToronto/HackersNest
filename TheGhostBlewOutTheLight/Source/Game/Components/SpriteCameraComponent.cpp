#include "SpriteCameraComponent.h"
#include "GameEngine/Util/CameraManager.h"
#include "GameEngine/EntitySystem/Component.h"
#include "GameEngine/EntitySystem/Entity.h"
#include <iostream>

using namespace Game;

void SpriteCameraComponent::Update()
{
    __super::Update();

    GameEngine::CameraManager::GetInstance()->GetCameraView().setCenter(GetEntity()->GetPos());
}

void SpriteCameraComponent::OnAddToWorld() {}