#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "Game/GameEntities/Player.h"
#include "Game/GameEntities/Bullet.h"

#include <SFML/System/Vector2.hpp>
#include <vector>

namespace Game
{
	//Used for storing and controlling all game related entities, as well as providing an entry point for the "game" side of application	
	class PlayerEntity;

	class GameBoard
	{
	public:
		GameBoard();
		virtual ~GameBoard();

		void Update();		
		bool IsGameOver() { return false; }

    private:
	    Game::Player *player1;
		Game::Player *player2;

		Game::Bullet *bullet;
	};
}

