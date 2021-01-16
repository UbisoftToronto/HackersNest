#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "Game/GameEntities/Player.h"
#include "Game/GameEntities/Bullet.h"
#include "Game/GameEntities/Text.h"

#include <SFML/System/Vector2.hpp>
#include <vector>

namespace Game
{


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
        void clearMenuGUIEntities();

        void buildGame();
        void updateRoundState();

    private:
        Game::Text* player1HealthGUI, * player2HealthGUI;
        Game::Text* countDownTimer, * roundTimer, * currentRoundGUI;
        Game::Text* titleText, * startText;

	    Game::Player *player1;
        Game::Player *player2;

        bool gameStarted = false;
        int currentRound;
        float roundStartCountdown;
        float currentRoundTimer;

        int player1NumWins;
        int player2NumWins;
	};
}

