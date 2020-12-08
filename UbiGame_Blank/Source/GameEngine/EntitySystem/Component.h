#pragma once
namespace GameEngine
{
	class Entity;

	class Component
	{
	public:
		Component();		
		virtual ~Component();
		virtual void Update();

		virtual void OnAddToWorld() {};
		virtual void OnRemoveFromWorld() {};

		//No need to call that, entity is set automatically in GameEngineMain
		void    SetEntity(Entity* ent) { m_entity = ent; }
		Entity* GetEntity() const { return m_entity; }

	private:
		Entity* m_entity;
	};
}

