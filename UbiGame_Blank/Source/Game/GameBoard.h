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
        void resetPlayers();

        void buildGame();
        void buildRound(int currentRound);
        void updateRoundState();
        void drawBackground();

        void checkPlayersHealthState();

    private:
        const int ROUND_DURATION = 10;
        const int MAX_ROUND_NUM = 3;

        Game::Text* player1HealthGUI, * player2HealthGUI;
        Game::Text* countDownTimer, * roundTimer, * currentRoundGUI;
        Game::Text* titleText, * startText, * htnText;
        GameEngine::Entity* htnLogo;

	      Game::Player *player1;
        Game::Player *player2;

        bool gameStarted = false;
        bool roundEnded = false;
        bool gameOver = false;
        int currentRound;
        float roundStartCountdown;
        float currentRoundTimer;
	};
}

