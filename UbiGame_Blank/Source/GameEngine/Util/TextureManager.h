#pragma once
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameEngine
{
	//TODO - if needed, move out of Engine part to some sort of loader on the game side of things
	namespace eTexture
	{
		enum type
		{
			None = -1,
			Player,
			Net,
			Background, 
			Hook,
			PongBall,
			GreyBlock,
			Enemy,
			Count,
		};
	}	

	inline const char* GetPath(eTexture::type texture)
	{
		switch (texture)
		{
			case eTexture::type::Player: return "Player.png";
			case eTexture::type::Net: return "Net.png";
			case eTexture::type::Background: return "Map.png";
			case eTexture::type::Hook: return "Hook.png";
			case eTexture::type::PongBall: return "PongBall.png";
			case eTexture::type::GreyBlock: return "GreyBlock.png";
			case eTexture::type::Enemy: return "Enemy.png";
		}
		return "Player.png";
	}

	class TextureManager
	{
	public:
		static TextureManager* GetInstance() { if (!sm_instance) sm_instance = new TextureManager(); return sm_instance; }
		~TextureManager();

		void LoadTextures();
		void UnLoadTextures();

		sf::Texture* GetTexture(eTexture::type texture) const { return m_textures[(int)texture]; }

	private:
		TextureManager();
		static TextureManager* sm_instance;

		sf::Texture* m_textures[eTexture::Count];
	};
}

namespace TextureHelper
{
	sf::Vector2f GetTextureTileSize(GameEngine::eTexture::type texture);
}

