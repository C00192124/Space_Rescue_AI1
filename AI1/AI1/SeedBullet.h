#pragma once
#include <SFML\Graphics.hpp>
#include "TextureLoader.h"
#include "BasicFunction.h"
class SeedBullet
{
public:
	SeedBullet(sf::Vector2f&, sf::Vector2f&, float&);
	~SeedBullet();
	void Render(sf::RenderWindow&);
	bool Update();
	sf::Sprite m_sprite;

private:
	sf::Texture m_bullet;

	sf::Vector2f m_pos;
	sf::Vector2f m_velocity;
	TextureLoader * m_TLoader;
	float m_speed = .0001;
	float orientation;
	bool m_alive;
	int timer=300;
};

