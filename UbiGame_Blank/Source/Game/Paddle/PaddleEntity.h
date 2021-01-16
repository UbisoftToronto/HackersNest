#pragma once
#include "GameEngine/EntitySystem/Entity.h"

//#include <SFML/System/Vector2.hpp>
//#include <vector>

namespace Game
{
	//Used for storing and controlling all game related entities, as well as providing an entry point for the "game" side of application	

	class PaddleEntity : public GameEngine::Entity
	{
	public:
		PaddleEntity();
		~PaddleEntity();

	protected:
		GameEngine::Entity* m_paddlerender;

	};
}
