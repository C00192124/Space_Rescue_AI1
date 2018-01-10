#pragma once
#include <SFML\Graphics.hpp>
#include "InputManager.h"
#include "BasicFunction.h"

class Player 
{
public:
	Player();
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
};

