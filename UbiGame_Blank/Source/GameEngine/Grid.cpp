#include "Grid.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/Util/TextureManager.h"
#include <GameEngine/EntitySystem/Components/SpriteRenderComponent.h>

using namespace Game;
Grid::Grid() 
	: top_border(nullptr), bottom_border(nullptr), left_border(nullptr), right_border(nullptr)
{
	CreateBorder();
}

Grid::~Grid() {

}


void Grid::CreateBorder() {

	GameEngine::Entity* bgEntity = new GameEngine::Entity();
	GameEngine::SpriteRenderComponent* render = bgEntity->AddComponent<GameEngine::SpriteRenderComponent>();
	render->SetTexture(GameEngine::eTexture::Background);
	render->SetZLevel(0);
	bgEntity->SetPos(sf::Vector2f(250.f, 250.f));
	bgEntity->SetSize(sf::Vector2f(500.f, 500.f));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(bgEntity);
	
	//m_backGround = bgEntity;

	top_border = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(top_border);
	bottom_border = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(bottom_border);
	left_border = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(left_border);
	right_border = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(right_border);
	float h = GameEngine::GameEngineMain::GetPixelHeight(100.f);
	float w = GameEngine::GameEngineMain::GetPixelWidth(100.f);
	float border_w = 10;
	top_border->SetPos(sf::Vector2f(w / 2, 0));
	top_border->SetSize(sf::Vector2f(w, border_w + 3));

	bottom_border->SetPos(sf::Vector2f(w / 2, h));
	bottom_border->SetSize(sf::Vector2f(w, border_w));

	left_border->SetPos(sf::Vector2f(0, h / 2));
	left_border->SetSize(sf::Vector2f(border_w, h));

	right_border->SetPos(sf::Vector2f(w, h / 2));
	right_border->SetSize(sf::Vector2f(border_w, h));

	GameEngine::RenderComponent* r_top = static_cast<GameEngine::RenderComponent*>(top_border->AddComponent<GameEngine::RenderComponent>());
	GameEngine::RenderComponent* r_bot = static_cast<GameEngine::RenderComponent*>(bottom_border->AddComponent<GameEngine::RenderComponent>());
	GameEngine::RenderComponent* r_left = static_cast<GameEngine::RenderComponent*>(left_border->AddComponent<GameEngine::RenderComponent>());
	GameEngine::RenderComponent* r_right = static_cast<GameEngine::RenderComponent*>(right_border->AddComponent<GameEngine::RenderComponent>());

	r_top->SetFillColor(sf::Color::Red);
	r_bot->SetFillColor(sf::Color::Yellow);
	r_left->SetFillColor(sf::Color::Blue);
	r_right->SetFillColor(sf::Color::Green);

	top_border->AddComponent<GameEngine::CollidableComponent>();
	bottom_border->AddComponent<GameEngine::CollidableComponent>();
	left_border->AddComponent<GameEngine::CollidableComponent>();
	right_border->AddComponent<GameEngine::CollidableComponent>();

	top_border->flag = 1;
	bottom_border->flag = 1;
	left_border->flag = 0;
	right_border->flag = 0;
	
}

void Grid::UpdatePixel(float x, float y) {
	
	sf::Texture* background = GameEngine::TextureManager::GetInstance()->GetTexture(GameEngine::eTexture::Background);
	sf::Image img = background->copyToImage();
	sf::Color check = img.getPixel(x, y);
	img.setPixel(x, y,sf::Color::Blue);
	background->loadFromImage(img);
}