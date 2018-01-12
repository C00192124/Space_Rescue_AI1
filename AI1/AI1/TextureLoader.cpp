#include "TextureLoader.h"

TextureLoader* TextureLoader::TLInstance = 0;

void TextureLoader::addTexture(std::string Tag, std::string Path)
{
	sf::Texture LoadTexture;
	if (!(LoadTexture.loadFromFile(Path)))
	{
	}
	else
	{
		Textures[Tag] = LoadTexture;
	}
}

sf::Texture TextureLoader::getTexture(std::string Tag)
{
	return Textures[Tag];
}