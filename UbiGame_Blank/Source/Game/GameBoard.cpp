#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "Game/GameComponents/PlayerMovementComponent.h"
#include "Game/GameEntities/Text.h"

using namespace Game;

GameBoard::GameBoard() : player1(nullptr), player2(nullptr), bullet(nullptr)

{
    int player1Controls[4] = { sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::W, sf::Keyboard::S };
    int player2Controls[4] = { sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Up, sf::Keyboard::Down };

    player1 = new Game::Player();
    player1->setControls(player1Controls);
    GameEngine::GameEngineMain::GetInstance()->AddEntity(player1);

    player2 = new Game::Player();
    player2->setControls(player2Controls);
    GameEngine::GameEngineMain::GetInstance()->AddEntity(player2);
    
}


GameBoard::~GameBoard()
{

}

void GameBoard::Update()
{	
  //Listen for SPACE to change gameStarted
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
    gameStarted = true;
  }

  updateGUI();

}

void GameBoard::updateGUI()
{
  if(!gameStarted){
    buildMenuGUI();
  } else{
    buildGameGUI();
  }
}


void GameBoard::buildMenuGUI()
{
  clearGUIEntities();

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
  clearGUIEntities();

  Text* player1Health = new Text("P1: 50", sf::Color::White, 30, sf::Vector2f(0.0f + 3 * 30, 30.0f));
  GameEngine::GameEngineMain::GetInstance()->AddEntity(player1Health);
  Text* player2Health = new Text("P2: 50", sf::Color::White, 30, sf::Vector2f(1024.0f - 3 * 30, 30.0f));
  GameEngine::GameEngineMain::GetInstance()->AddEntity(player2Health);

  Text* roundTimer = new Text("15", sf::Color::White, 50, sf::Vector2f(1024.0f/2, 50.0f));
  GameEngine::GameEngineMain::GetInstance()->AddEntity(roundTimer);

  guiEntities.push_back(player1Health);
  guiEntities.push_back(player2Health);
  guiEntities.push_back(roundTimer);
}

void GameBoard::clearGUIEntities()
{
  for(std::vector<GameEngine::Entity*>::iterator it = guiEntities.begin(); it != guiEntities.end();){
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
