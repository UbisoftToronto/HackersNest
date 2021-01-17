#pragma once
#include "GameEngine/EntitySystem/Component.h"
#include <SFML/Window/Keyboard.hpp>
#include "Game/GameEntities/Bullet.h"

namespace Game
{
	class PlayerActionComponent : public GameEngine::Component
	{
	public:
		PlayerActionComponent();
		~PlayerActionComponent();

		virtual void Update();
		virtual void OnAddToWorld();

		void setPlayerAction(int playerAction);
		void disableInput(bool disable);
	private:
		int playerActionKey;
		bool firePressed;
		bool inputDisabled = false;

		void spawnBullet();
	};
}