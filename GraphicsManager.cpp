#include <SFML/Graphics.hpp>
#include "GraphicsManager.hpp"

namespace TheFrog
{
	void GraphicsManager::LoadTexture(std::string name, std::string fileName)
	{
		sf::Texture tex;

		if (tex.loadFromFile(fileName))
		{
			this->_textures[name] = tex;
		}
	}

	sf::Texture &GraphicsManager::GetTexture(std::string name)
	{
		return this->_textures.at(name);
	}

	void GraphicsManager::LoadFont(std::string name, std::string fileName)
	{
		sf::Font font;

		if (font.loadFromFile(fileName))
		{
			this->_fonts[name] = font;
		}
	}

	sf::Font &GraphicsManager::GetFont(std::string name)
	{
		return this->_fonts.at(name);
	}
}