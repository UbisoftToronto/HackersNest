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
			Player1,
      Player2,
      Background,
      Box,
      htn,
      Count,
		};
	}	

	inline const char* GetPath(eTexture::type texture)
	{
		switch(texture)
    {
      case eTexture::Player1: return "PlayerOne.png";
      case eTexture::Player2: return "PlayerOne.png";
      case eTexture::Background: return "Background.png";
      case eTexture::Box:return "Box.png";
      case eTexture::htn: return "htn.png";
    }
    return "UnknownTexType";
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

