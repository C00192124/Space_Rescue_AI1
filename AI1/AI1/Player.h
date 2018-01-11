#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "InputManager.h"
#include "BasicFunction.h"
#include "Worker.h"

class Player 
{
public:
	Player();
	Player(InputManager *i);
	~Player();
	void Render(sf::RenderWindow &w);
	void Update(std::vector<Worker> *w);
	sf::View GetView();
	sf::Sprite m_Player;

private:
	//Player Variables
	sf::Texture m_PlayerTexture;

	sf::Vector2f m_Velocity;

	InputManager *m_Input;

	sf::View camera;
	
	float m_Speed;
	float m_Orientation;

	void Collision(std::vector<Worker> *w);
};

