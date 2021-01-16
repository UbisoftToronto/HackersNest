#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "Game/GameEntities/Player.h"
#include "Game/GameEntities/Bullet.h"
#include "Game/GameEntities/Text.h"

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

    void setGameStarted(bool newState);
    bool getGameStarted();

    void buildMenuGUI();
    void buildGameGUI();
    void updateGUI();
    void clearGUIEntities();

    void buildGame();
    void updateRoundState();

    private:
	    std::vector<Game::Text*> guiEntities;
	    Game::Player *player1;
      Game::Player *player2;
      Game::Bullet *bullet;

      bool gameStarted = false;
      int currentRound;
      int roundStartCountdown;
      float currentRoundTimer;
      int player1NumWins;
      int player2NumWins;
      int player1Health;
      int player2Health;
	};
}

