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

		////////////////////////////////// Garbage sort game //////////////////////////////////

		void SortGarbage();

		void CreateImage(GameEngine::eTexture::type texture, float x, float y);
		GameEngine::Entity* image;

		////////////////////////////////// Work from Home //////////////////////////////////
		
		void Wfh();
		GameEngine::Entity* wfh;

		////////////////////////////////// Wash Hand game //////////////////////////////////

		bool wh_isGameOver = false;
		float lastWaterSpawnTimer; 
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
		bool maskWin = false
		float lastMaskSpawnTime;
		int maskCount = 0;

        void CreateMaskPlayer();
        GameEngine::Entity* maskplayer;

		void CreateMask();
		GameEngine::Entity* mask;

		void UpdateMask();
        void PutOnMask();
		void UpdatePutOnMask();
	};
}

