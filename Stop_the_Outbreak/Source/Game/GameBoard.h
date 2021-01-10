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
		void CreatePlayer();          // <-- Added Function
		GameEngine::Entity* m_player; // <-- Added Member

		void CreateBackground(GameEngine::eTexture::type texture);
		GameEngine::Entity* background;

		void CleanTheBox();
		GameEngine::Entity* cleanTheBox;

		void SortGarbage();
		GameEngine::Entity* sortGarbage;

		void CreateImage(GameEngine::eTexture::type texture, float x, float y);
		GameEngine::Entity* image;

		void Wfh();
		GameEngine::Entity* wfh;

		void BakingBread();
		GameEngine::Entity* bakingBread;

		void CreateHandPlayer();
		GameEngine::Entity* handplayer;

		void CreateWater();
		GameEngine::Entity* water;

		void WashHands();
		GameEngine::Entity* washHands;

        void CreateMaskPlayer();
        GameEngine::Entity* maskplayer;

		void CreateMask();
		GameEngine::Entity* mask;

        void PutOnMask();
        GameEngine::Entity* putOnMask;

		void TransitionPage();
		GameEngine::Entity* transitionPage;
	};
}

