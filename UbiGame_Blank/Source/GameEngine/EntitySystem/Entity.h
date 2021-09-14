#pragma once
#include <SFML/System/Vector2.hpp>
#include <optional>
#include <string>
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

        void SetEntityTag(std::string tag);
        void ClearEntityTag();
        std::string GetEntityTag() const;
        bool HasEntityTag() const;

        virtual void Update();

        //Base entity params
        sf::Vector2f GetPos() const;
        sf::Vector2f GetSize() const;
        float		 GetRot()  const;

        void		 SetPos(sf::Vector2f pos);
        void		 SetSize(sf::Vector2f size) { m_size = size; }
        void	     SetRotation(float rotation) { m_rotation = rotation; }

        sf::Vector2f GetLocalPosOffset() const { return m_localPosOffset; }
        float		 GetLocalRotOffset() const { return m_localRotOffset; }

        void		 SetLocalPosOffset(sf::Vector2f localPosOffset) { m_localPosOffset = localPosOffset; }
        void		 SetLocalRotOffset(float localRotOffset) { m_localRotOffset = localRotOffset; }

        void		 SetParent(Entity* entity, bool retainWorldPos = false);
        void		 RemoveParent();

        void		 AddChild(Entity* entity);
        void		 RemoveChild(Entity* entity);
        void		 ClearChildren();

        const Entity* GetParent() const { return m_parent; }
        const std::vector<Entity*>& GetChildren() const { return m_children; }

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
        std::vector<T*> GetAllComponents()
        {
            std::vector<T*> outVec;
            for (int a = 0; a < m_components.size(); ++a)
            {
                Component* comp = m_components[a];
                T* searched = dynamic_cast<T*>(comp);
                if (searched)
                    outVec.push_back(searched);
            }
            return outVec;
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

        std::vector<Entity*>   m_children;
        Entity* m_parent;

        sf::Vector2f		   m_localPosOffset;
        float				   m_localRotOffset;

        std::optional<std::string> m_entityTag;
    };
}
