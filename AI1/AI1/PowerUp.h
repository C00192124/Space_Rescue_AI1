#pragma once
#include <SFML/Graphics.hpp>
#include "BasicFunction.h"
#include "TextureLoader.h"

class PowerUp 
{
public:
	PowerUp();
	~PowerUp();
	void Render(sf::RenderWindow &w);
	void Update();
	
	sf::Sprite m_PowerUp;

private:

	//Power Up Variables
	TextureLoader * m_TLoader;
	sf::Texture m_PowerUpTexture;
	sf::Vector2f m_PowerUpPosition;
	float m_pUpDuration;


};

