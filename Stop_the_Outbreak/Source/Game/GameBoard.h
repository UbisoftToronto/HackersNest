#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/Util/TextureManager.h"

#include <SFML/System/Vector2.hpp>
#include <vector>

namespace Game
{	
	class PlayerEntity;	

	class GameBoard
	{
	public:
		GameBoard();
		virtual ~GameBoard();

		void Update();
		bool IsGameOver() { return false; }

	protected:
		float RandomFloatRange(float a, float b)
		{
			return ((b - a) * ((float)rand() / RAND_MAX)) + a;
		}

	private:
		void CreateBackground(GameEngine::eTexture::type texture);
		GameEngine::Entity* background;

		int lives;
		bool sg_played = false;
		bool wfh_played = false;
		bool wh_played = false;

		int GameGenerator();

		////////////////////////////////// Garbage sort game //////////////////////////////////
		void MenuPage();
		GameEngine::Entity* menuPage;

		void SortGarbage();
		GameEngine::Entity* sortGarbage;

		GameEngine::Entity* CreateImage(GameEngine::eTexture::type texture, float x, float y, float size_x, float size_y);

		////////////////////////////////// Work from Home //////////////////////////////////
		
		void Wfh();
		GameEngine::Entity* wfh;

		////////////////////////////////// Wash Hand game //////////////////////////////////

		bool wh_isGameOver = false;
		float lastWaterSpawnTimer = 0.9f; 
		int waterCount = 0;
		int caughtWaterCount = 0;

		void CreateHandPlayer();
		GameEngine::Entity* handplayer;

		void CreateWater();
		GameEngine::Entity* water;
		std::vector<GameEngine::Entity*> waters;

		void UpdateWaters();
		void WashHands();
		void UpdateWashHands();

		////////////////////////////////// Mask game //////////////////////////////////

		bool m_isGameOver = false;
		bool maskWin = false;
		float lastMaskSpawnTime = 1.f;
		int maskCount = 0;

        void CreateMaskPlayer();
        GameEngine::Entity* maskplayer;

		void CreateMask();
		GameEngine::Entity* mask;

		void UpdateMask();
        void PutOnMask();
		void UpdatePutOnMask();
        GameEngine::Entity* putOnMask;

		////////////////////////////////// Transition pages //////////////////////////////////

		void TransitionPage();
		GameEngine::Entity* transitionPage;

		GameEngine::Entity* mask_1;

		GameEngine::Entity* mask_2;

		GameEngine::Entity* mask_3;
	};
}

