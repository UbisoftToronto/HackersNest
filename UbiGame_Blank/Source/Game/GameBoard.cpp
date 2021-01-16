#include "GameBoard.h"
#include "GameEngine/GameEngineMain.h"
#include "Game/GameComponents/PlayerMovementComponent.h"
#include "Game/GameEntities/Text.h"

#include <string>
#include <math.h>

using namespace Game;

GameBoard::GameBoard() : player1(nullptr), player2(nullptr), bullet(nullptr)
{
    buildMenuGUI();
}


GameBoard::~GameBoard()
{

}

void GameBoard::Update()
{
  //Listen for SPACE to change gameStarted
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !gameStarted){
    gameStarted = true;
    buildGame();
    clearGUIEntities();
    buildGameGUI();
    return;
  }

  if(gameStarted)
  {
    updateRoundState();
    updateGUI();
  }
}

void GameBoard::updateRoundState()
{
  if(roundStartCountdown > 0){
    roundStartCountdown -= GameEngine::GameEngineMain::GetTimeDelta();
    return;
  }

  if(currentRoundTimer > 0){
    currentRoundTimer -= GameEngine::GameEngineMain::GetTimeDelta();
  } else {
    currentRoundTimer = 20;
    currentRound++;
    roundStartCountdown = 3;
  }
}

void GameBoard::buildGame()
{
  //Initalize game states
  currentRound = 1;
  currentRoundTimer = 20;
  roundStartCountdown = 3;
  player1NumWins = 0;
  player2NumWins = 0;
  player1Health = 100;
  player2Health = 100;

    int player1Controls[6] = { sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::Q, sf::Keyboard::E };
    int player2Controls[6] = { sf::Keyboard::Numpad1, sf::Keyboard::Numpad3, sf::Keyboard::Numpad5, sf::Keyboard::Numpad2, sf::Keyboard::Numpad4, sf::Keyboard::Numpad6 };

    player1 = new Game::Player();
    player1->setControls(player1Controls);
    player1->setActionButton(sf::Keyboard::Space);
    GameEngine::GameEngineMain::GetInstance()->AddEntity(player1);

    player2 = new Game::Player();
    player2->setControls(player2Controls);
    player2->setActionButton(sf::Keyboard::Enter);
    GameEngine::GameEngineMain::GetInstance()->AddEntity(player2);
}

void GameBoard::updateGUI()
{
}


void GameBoard::buildMenuGUI()
{
  const std::string gameName = "BulletTime";
  const std::string startGameText = "Press Space to start!";

  Text* titleText = new Text(gameName, sf::Color::White, 75, sf::Vector2f(1024.0f/2, 50.0f));
  GameEngine::GameEngineMain::GetInstance()->AddEntity(titleText);
  Text* startText = new Text(startGameText, sf::Color::White, 30, sf::Vector2f(1024.0f/2, 700.0f));
  GameEngine::GameEngineMain::GetInstance()->AddEntity(startText);

  guiEntities.push_back(titleText);
  guiEntities.push_back(startText);
}

void GameBoard::buildGameGUI() 
{
  Text* player1HealthGUI = new Text("P1: " + std::to_string(player1Health), sf::Color::White, 30, sf::Vector2f(0.0f + 3 * 30, 30.0f));
  GameEngine::GameEngineMain::GetInstance()->AddEntity(player1HealthGUI);
  Text* player2HealthGUI = new Text("P2: " + std::to_string(player2Health), sf::Color::White, 30, sf::Vector2f(1024.0f - 3 * 30, 30.0f));
  GameEngine::GameEngineMain::GetInstance()->AddEntity(player2HealthGUI);

  Text* roundTimer = new Text(std::to_string((int)ceil(currentRoundTimer)), sf::Color::White, 50, sf::Vector2f(1024.0f/2, 150.0f));
  GameEngine::GameEngineMain::GetInstance()->AddEntity(roundTimer);
  Text* currentRoundGUI = new Text("Round " + std::to_string(currentRound), sf::Color::White, 50, sf::Vector2f(1024.0f/2, 50.0f));
  GameEngine::GameEngineMain::GetInstance()->AddEntity(currentRoundGUI);

  guiEntities.push_back(player1HealthGUI);
  guiEntities.push_back(player2HealthGUI);
  guiEntities.push_back(roundTimer);
  guiEntities.push_back(currentRoundGUI);
}

void GameBoard::clearGUIEntities()
{
  for(std::vector<Game::Text*>::iterator it = guiEntities.begin(); it != guiEntities.end();)
  {
    GameEngine::GameEngineMain::GetInstance()->RemoveEntity(*it);
    it = guiEntities.erase(it);
  }
  
}

void GameBoard::setGameStarted(bool newState) {
    gameStarted = newState;
}

bool GameBoard::getGameStarted() {
    return gameStarted;
}
