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
	
	sf::Vector2f m_PlayerPosition;
	sf::Sprite m_Player;

private:
	//Player Variables
	sf::Texture m_PlayerTexture;


	sf::Vector2f m_Velocity;
	
	InputManager *m_Input;

	sf::View camera;
	
	float m_Speed;
	float m_Orientation;
};

