#pragma once
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"

namespace GameEngine
{
	//This one allows for movement and obstacle detection,
	class CollidablePhysicsComponent : public CollidableComponent
	{
	public:
		CollidablePhysicsComponent();
		virtual ~CollidablePhysicsComponent();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

		virtual void Update() override;

		bool DidCollide() const { return m_didCollide; }
		Entity *GetLastCollideEntity() const { return m_lastCollideEntity; }

	protected:
		bool m_didCollide;
		Entity *m_lastCollideEntity;
	};
}
