#pragma once
#include "GameEngine/EntitySystem/Component.h"
#include <SFML/Window/Keyboard.hpp>
#include "Game/GameEntities/Bullet.h"

namespace Game
{
	class PlayerActionComponent : public GameEngine::Component
	{
	public:
		virtual void Update();
		virtual void OnAddToWorld();

		void setPlayerAction(int playerAction);
	private:
		int playerAction;
		Game::Bullet* bullet;

	};
}