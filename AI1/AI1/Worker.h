#pragma once
#include <SFML/Graphics.hpp>
#include "BasicFunction.h"
#include "GameWorld.h"

class Worker 
{
public:
	Worker();
	~Worker();

	void Render(sf::RenderWindow &w);
	void Update(GameWorld &w);
	
	sf::Sprite m_Worker;

private:

	// Worker Variables
	sf::Vector2f m_WorkerVelocity;
	sf::Vector2f m_WorkerPosition;
	sf::Vector2f wanderTarget = sf::Vector2f(0.0, 0.0);

	sf::Texture m_WorkerTexture;
	
	float time = 5.0f;
	float distance;
	float radius = 500.0f;
	float m_WorkerOrientation;
};

