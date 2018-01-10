#pragma once
#include "SFML\Graphics.hpp"
#include "BasicFunction.h"
#include <math.h>
#include <time.h>

class AlienNest
{
public:
	AlienNest();
	~AlienNest();
	void Render(sf::RenderWindow &w);
	void Update();
	
private:

	//Alien Nest Variables
	sf::Texture m_NestTexture;
	sf::Sprite m_Nest;
	int randx;
	int randy;



};

