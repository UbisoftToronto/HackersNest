#include "BallEntity.h"

using namespace Game;

BallEntity::BallEntity()
{
	//Movement
	ballMovementComponent = AddComponent<BallMovementComponent>();

	//Collision
	ball = AddComponent<GameEngine::CollidablePhysicsComponent>();

	//Render
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetFillColor(sf::Color::Transparent);
	m_renderComponent->SetTexture(GameEngine::eTexture::Ball);
	m_renderComponent->SetZLevel(2);
}

BallEntity::~BallEntity()
{

}