#pragma once
#include "GameEngine/EntitySystem/Entity.h"

#include <SFML/System/Vector2.hpp>
#include <vector>

namespace Game
{
	//Used for storing and controling all game related entities
	class PlayerEntity;	
	class VirusEntity;

	class GameBoard
	{
	public:
		GameBoard();
		virtual ~GameBoard();

		//Temp - for nice architecture this should be within some sort of IUpdatable interface that GameEngine handles (so that not only entities can be updated)
		void Update();

		void CreatePlayer();
		void CreateBackground();
		void CreatePlatform(float x, float y, int id);
		void CreateVirus(sf::Vector2f start, sf::Vector2f end, sf::Vector2f initialPos);
		void CreateTestProjectile();

		bool IsGameOver() const { return m_isGameOver; }

	protected:
		//Placeholder temp - should go to helpers or smth.

		PlayerEntity* m_player;
		GameEngine::Entity* m_text;
		GameEngine::Entity* m_backGround;
		VirusEntity* m_virus;

		bool m_isGameOver;
	};
}
