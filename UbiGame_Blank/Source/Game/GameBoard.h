#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/Grid.h"
#include <SFML/System/Vector2.hpp>
#include <vector>
#include "Game/Scoreboard/Entities/ScoreboardEntity.h"

namespace Game
{
	//Used for storing and controlling all game related entities, as well as providing an entry point for the "game" side of application	
	class PaddleEntity; 
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
		PaddleEntity* left_paddle;
		PaddleEntity* right_paddle;

		Game::Grid* Border;

		void CreateBall();
		BallEntity* ball;

		void CreateScoreboard();
		ScoreboardEntity* scoreboard;
	};
}

