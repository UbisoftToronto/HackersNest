#include "TreasureComponent.h"
#include "GameEngine/EntitySystem/Component.h"
#include "GameEngine/EntitySystem/Entity.h"
#include <iostream>
#include <SFML\Graphics\Rect.hpp>

using namespace Treasure;

void TreasureComponent::Update()
{
	sf::IntRect r1(0, 0, 20, 5);
	Component::GetEntity()->Entity::GetPos();
	bool b1 = r1.contains(3, 1);
	if (b1) {
		std::cout << "INTERSECTED" << std::endl;
	}
}

void TreasureComponent::OnAddToWorld() {}