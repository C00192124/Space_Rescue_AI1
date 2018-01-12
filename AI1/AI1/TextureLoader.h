#pragma once
#include <iostream>
#include <map>
#include <string>
#include "SFML\Graphics.hpp"

class TextureLoader
{
private:
	static TextureLoader * TLInstance;
	std::map<std::string, sf::Texture> Textures;
	TextureLoader()
	{
		Textures = std::map<std::string, sf::Texture>();
	};

public:

	void addTexture(std::string Tag, std::string Path);

	sf::Texture getTexture(std::string Tag);

	static TextureLoader * Instance()
	{
		if (!TLInstance)
		{
			TLInstance = new TextureLoader;
		}

		return TLInstance;
	}
};