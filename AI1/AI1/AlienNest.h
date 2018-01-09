#pragma once
#include "SFML\Graphics.hpp"
#include "GameObject.h"

class AlienNest : public GameObject
{
public:
	AlienNest();
	~AlienNest();
	void Update();
	void Render(sf::RenderWindow &);


private:

	//Alien Nest Variables

	sf::Texture m_NestTexture;
	sf::Sprite m_Nest;
	int m_MaxNests;



};

