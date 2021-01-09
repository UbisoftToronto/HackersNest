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

			CleanBox_bg,
			SortGarbage_bg,
			WFH_bg,
			BakeBread_bg,
			WashYoHands_bg,
			PutOnMask_bg,
			Garbage,
			Compost,
			Recycling,


			Count,
		};
	}	

	inline const char* GetPath(eTexture::type texture)
	{
		switch (texture)
		{
			case eTexture::Player: return "download.png"; 
			case eTexture::type::CleanBox_bg: return "placeholder_bg.jpg";
			case eTexture::type::SortGarbage_bg: return "placeholder_bg.jpg";
			case eTexture::type::WFH_bg: return "placeholder_bg.jpg";
			case eTexture::type::BakeBread_bg: return "placeholder_bg.jpg";
			case eTexture::type::WashYoHands_bg: return "placeholder_bg.jpg";
			case eTexture::type::PutOnMask_bg: return "placeholder_bg.jpg";

			case eTexture::type::Garbage: return "Garbage_Bin.png";
			case eTexture::type::Compost: return "Compost_Pit.png";
			case eTexture::type::Recycling: return "Recycling_Sign.png";
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

