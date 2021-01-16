#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/Grid.h"
#include <SFML/System/Vector2.hpp>
#include <vector>

namespace Game
{
	//Used for storing and controlling all game related entities, as well as providing an entry point for the "game" side of application	
	class PlayerEntity;
	class BallEntity;

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

		GameEngine::Grid* Border;

		void CreateBall();
		BallEntity* ball;

	
		

		void CreateScoreboard();
		GameEngine::Entity* scoreboard;
	};
}

