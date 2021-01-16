#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include <SFML/System/Vector2.hpp>
#include <vector>

namespace Game {
	
	class Grid
	{
	public:
		
		Grid();
		~Grid();
		void CreateBorder();
		void UpdatePixel(float x, float y);
		GameEngine::Entity* top_border;
		GameEngine::Entity* bottom_border;
		GameEngine::Entity* left_border;
		GameEngine::Entity* right_border;
		GameEngine::Entity* bgEntity;
	};


}