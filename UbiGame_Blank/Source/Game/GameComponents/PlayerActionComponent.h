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
	private:
		int playerActionKey;
		Game::Bullet* bullet;
		bool firePressed;

		void spawnBullet();
	};
}