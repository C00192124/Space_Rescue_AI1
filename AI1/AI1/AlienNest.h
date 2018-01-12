#pragma once
#include "SFML\Graphics.hpp"
#include "BasicFunction.h"
#include <iostream>
#include <math.h>
#include <time.h>

class AlienNest
{
public:
	AlienNest();
	~AlienNest();
	void Render(sf::RenderWindow &w);
	void Update(sf::Sprite &p);
	void FindPlayerPosition(int,int);
	void FireStinger(int, int);
	void CheckPlayerCollision(sf::Sprite &p);

private:

	//Alien Nest Variables
	sf::Texture m_NestTexture;
	sf::Sprite m_Nest;	
	sf::Vector2f m_NestPosition;

	int randx;
	int randy;

	int m_nestHealth;
	bool m_nestAlive;

	bool m_FoundPlayer;
	float m_TotalDistance;

	//Missile Variables 
	sf::Texture m_MissileTexture;
	sf::Sprite m_Missile;
	sf::Vector2f m_MissilePosition;
	sf::Vector2f m_MissileVelocity;

	bool m_MissileAlive;
	bool m_PlayerHit;
	int m_MissileLifeTime;

	int m_FiringRange;
	float m_Speed;
	float m_MissileOrientation;

};

