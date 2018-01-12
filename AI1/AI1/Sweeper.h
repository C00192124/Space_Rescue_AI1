#pragma once
#include <SFML/Graphics.hpp>
#include "BasicFunction.h"
#include "GameWorld.h"
#include "Worker.h"

using namespace std;

class Sweeper
{
public:
	Sweeper();
	~Sweeper();

	void Render(sf::RenderWindow &w);
	void Update(GameWorld &w, sf::Sprite &p, vector<Worker> t);

	sf::Sprite m_Sweeper;

private:

	// Sweeper Variables
	sf::Vector2f m_SweeperVelocity;
	sf::Vector2f m_SweeperPosition;
	sf::Vector2f wanderTarget = sf::Vector2f(0.0, 0.0);
	sf::Texture m_SweeperTexture;

	float time = 5.0f;
	float distance;
	float radius = 500.0f;
	float m_SweeperOrientation;

	bool attack;
	bool wander;
	bool flee;

	sf::Vector2f temp;
	int prey;

	bool Collision(sf::Sprite &s);
	bool CheckRange(int x, int y, int range);
};

