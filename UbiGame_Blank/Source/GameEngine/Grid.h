#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include <SFML/System/Vector2.hpp>
#include <vector>
#include "Game/Scoreboard/Entities/ScoreboardEntity.h"

namespace Game {
	
	class Grid
	{
	public:
		
		Grid();
		
		~Grid();
		void CreateBorder();
		void UpdatePixel(float x, float y, int plyn, ScoreboardEntity* scoreboard);
		GameEngine::Entity* top_border;
		GameEngine::Entity* bottom_border;
		GameEngine::Entity* left_border;
		GameEngine::Entity* right_border;
		GameEngine::Entity* bgEntity;
		int p1 = 0;
		int p2 = 0;
	};


}