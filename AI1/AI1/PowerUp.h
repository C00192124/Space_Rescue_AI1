#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "GameObject.h"

class PowerUp: GameObject
{
public:
	PowerUp();
	~PowerUp();
	void Render(sf::RenderWindow &w);
	void update();
	void Collision(Player* p);

private:

	//Power Up Variables
	sf::Texture m_PowerUpTexture;
	sf::Sprite m_PowerUp;
	sf::Vector2f m_PowerUpPosition;

};

