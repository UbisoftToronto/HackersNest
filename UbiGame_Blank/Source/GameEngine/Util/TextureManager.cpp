#include "TextureManager.h"

using namespace GameEngine;

TextureManager *TextureManager::sm_instance = nullptr;

TextureManager::TextureManager()
{
	for (int a = 0; a < (int)eTexture::Count; ++a)
	{
		m_textures[a] = nullptr;
	}
}

TextureManager::~TextureManager()
{
	UnLoadTextures();
}

void TextureManager::LoadTextures()
{
	for (int a = 0; a < (int)eTexture::Count; ++a)
	{
		sf::Texture *texture = new sf::Texture();
		std::string filePath;
		filePath.append("Resources/img/");
		filePath.append(GetPath((eTexture::type)a));
		texture->loadFromFile(filePath);

		m_textures[a] = texture;
	}
}

void TextureManager::UnLoadTextures()
{
	for (int a = 0; a < (int)eTexture::Count; ++a)
	{
		delete m_textures[a];
		m_textures[a] = nullptr;
	}
}

namespace TextureHelper
{
	sf::Vector2f GetTextureTileSize(GameEngine::eTexture::type texture)
	{
		switch (texture)
		{
		case GameEngine::eTexture::Player:
			return sf::Vector2f(63.f, 58.f);
		case GameEngine::eTexture::PlayerLeft:
			return sf::Vector2f(63.f, 58.f);
		case GameEngine::eTexture::Tileset:
			return sf::Vector2f(24.f, 8.f);
		case GameEngine::eTexture::Tileset3:
			return sf::Vector2f(54.f, 8.f);
		case GameEngine::eTexture::Tileset4:
			return sf::Vector2f(70.f, 8.f);
		case GameEngine::eTexture::Projectile:
			return sf::Vector2f(28.f, 17.f);
		case GameEngine::eTexture::ProjectileLeft:
			return sf::Vector2f(28.f, 17.f);
		case GameEngine::eTexture::BG:
			return sf::Vector2f(100.f, 100.f);
		case GameEngine::eTexture::Particles:
			return sf::Vector2f(31.f, 32.f);
		case GameEngine::eTexture::Virus:
			return sf::Vector2f(43.f, 43.f);
		case GameEngine::eTexture::Border:
			return sf::Vector2f(30.f, 8.f);
		default:
			return sf::Vector2f(-1.f, -1.f);
		}
	}
}
