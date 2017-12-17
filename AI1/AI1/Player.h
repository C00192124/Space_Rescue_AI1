#pragma once
#include <SFML\Graphics.hpp>
#include "InputManager.h"
#include "GameObject.h"

class Player: public GameObject
{
public:
	Player(InputManager *i);
	~Player();
	void Render(sf::RenderWindow &w);
	void Update();
	sf::View GetView();

private:
	//Player Variables
	sf::Texture m_PlayerTexture;
	sf::Sprite m_Player;

	sf::Vector2f m_Velocity;

	InputManager *m_Input;

	sf::View camera;
	
	float m_Speed;
	float m_Orientation;

	sf::Vector2f setVelocity(float &currentOrientation);
};

