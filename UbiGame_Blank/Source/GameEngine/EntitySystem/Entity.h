#pragma once
#include <SFML/System/Vector2.hpp>
#include <vector>
#include "GameEngine/EntitySystem/Component.h"

namespace GameEngine
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		virtual void OnAddToWorld();
		virtual void OnRemoveFromWorld();

		virtual void Update();

		//Base entity params
		sf::Vector2f GetPos()  const { return m_pos; }
		sf::Vector2f GetSize() const { return m_size; }
		float		 GetRot()  const { return m_rotation; }
		
		void		 SetPos(sf::Vector2f pos)   { m_pos = pos; }
		void		 SetSize(sf::Vector2f size) { m_size = size; }
		void	     SetRotation(float rotation) { m_rotation = rotation; }		

		//Components
		template <class T>
		T* GetComponent()
		{
			for (int a = 0; a < m_components.size(); ++a)
			{
				Component* comp = m_components[a];
				T* searched = dynamic_cast<T*>(comp);
				if (searched)
					return searched;
			}

			return nullptr;
		}

		template <class T>
		T* AddComponent()
		{
			T* newComponent = new T();
			newComponent->SetEntity(this);
			m_components.push_back(newComponent);
			
			return newComponent;
		}

	protected:
		void DestroyComponents();

		std::vector<Component*> m_components;
		sf::Vector2f		   m_pos;
		sf::Vector2f		   m_size;		
		float				   m_rotation;
	};
}
