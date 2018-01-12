#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "InputManager.h"
#include "BasicFunction.h"
#include "Worker.h"
#include "PowerUp.h"
#include "AlienNest.h"
#include "SeedBullet.h"

class Player 
{
public:
	Player();
	Player(InputManager *i);
	~Player();
	void Render(sf::RenderWindow &w);
	void Update(std::vector<Worker> *w, std::vector<PowerUp> *pUp, std::vector<AlienNest> *ANest);
	void fire();
	sf::View GetView();
	sf::Sprite m_Player;
	
	std::vector<SeedBullet> bullets;
	

private:
	//Player Variables
	sf::Texture m_PlayerTexture;

	sf::Vector2f m_Velocity;


	InputManager *m_Input;

	sf::View camera;
	float m_Speed;
	
	bool powerUpBool;
	int powerUpTimer=180;
	int tim = 50;
	float m_Orientation;

	void Collision(std::vector<Worker> *w, std::vector<PowerUp> *pUp, std::vector<AlienNest> *ANest);
};

