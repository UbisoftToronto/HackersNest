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
			Player = 0,
			PlayerLeft,
			Tileset,
			Tileset3,
			Tileset4,
			BG,
			Projectile,
			ProjectileLeft,
			Particles,
			Virus,
			Border,
			Count,
		};
	}

	inline const char *GetPath(eTexture::type texture)
	{
		switch (texture)
		{
		case eTexture::Player:
			return "player.png";
		case eTexture::PlayerLeft:
			return "playerleft.png";
		case eTexture::Tileset:
			return "tileset.png";
		case eTexture::Tileset3:
			return "tileset3.png";
		case eTexture::Tileset4:
			return "tileset4.png";
		case eTexture::BG:
			return "bg.png";
		case eTexture::Projectile:
			return "antibody.png";
		case eTexture::ProjectileLeft:
			return "antibodyleft.png";
		case eTexture::Particles:
			return "particles.png";
		case eTexture::Virus:
			return "virus.png";
		case eTexture::Border:
			return "border.png";
		default:
			return "UnknownTexType";
		}
	}

	class TextureManager
	{
	public:
		static TextureManager *GetInstance()
		{
			if (!sm_instance)
				sm_instance = new TextureManager();
			return sm_instance;
		}
		~TextureManager();

		void LoadTextures();
		void UnLoadTextures();

		sf::Texture *GetTexture(eTexture::type texture) const { return m_textures[(int)texture]; }

	private:
		TextureManager();
		static TextureManager *sm_instance;

		sf::Texture *m_textures[eTexture::Count];
	};
}

namespace TextureHelper
{
	sf::Vector2f GetTextureTileSize(GameEngine::eTexture::type texture);
}
