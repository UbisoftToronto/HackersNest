#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include <string>
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
		void CreatePlayer();
		GameEngine::Entity* m_player;
		void CreateBackground();
		void CreateObstacle(float x_cord, float y_cord, float width, float height, bool hit_box);

	};
}


