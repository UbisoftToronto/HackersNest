#pragma once
#include "GameEngine/EntitySystem/Entity.h"

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
		void CreatePaddle();
		GameEngine::Entity* left_paddle;
		GameEngine::Entity* right_paddle;

		void CreateBall();
		GameEngine::Entity* ball;

		void CreateBorder();
		GameEngine::Entity* top_border;
		GameEngine::Entity* bottom_border;
		GameEngine::Entity* left_border;
		GameEngine::Entity* right_border;

		void CreateScoreboard();
		GameEngine::Entity* scoreboard;
	};
}

