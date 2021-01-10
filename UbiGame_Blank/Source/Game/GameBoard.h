#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/Util/TextureManager.h"

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
		int lives;
		bool sg_played = false;
		bool wfh_played = false;
		bool wh_played = false;

		int GameGenerator();

		void CreatePlayer();          // <-- Added Function
		GameEngine::Entity* m_player; // <-- Added Member

		void CreateBackground(GameEngine::eTexture::type texture);
		GameEngine::Entity* background;

		void MenuPage();
		GameEngine::Entity* menuPage;

		void SortGarbage();
		GameEngine::Entity* sortGarbage;

		GameEngine::Entity* CreateImage(GameEngine::eTexture::type texture, float x, float y, float size_x, float size_y);

		void Wfh();
		GameEngine::Entity* wfh;

		void BakingBread();
		GameEngine::Entity* bakingBread;

		void WashHands();
		GameEngine::Entity* washHands;

		void PutOnMask();
		GameEngine::Entity* putOnMask;

		void TransitionPage();
		GameEngine::Entity* transitionPage;

		GameEngine::Entity* mask_1;

		GameEngine::Entity* mask_2;

		GameEngine::Entity* mask_3;
	};
}

