#pragma once
#include <SFML/Graphics.hpp>

class Worker
{
public:
	Worker();
	~Worker();

	void Render(sf::RenderWindow &w);
	void update();
	float length(sf::Vector2f vec);
	float GetOreintation();
	void MoveWorker();
	sf::Vector2f Normalise(sf::Vector2f vec);

private:

	void Wander(float & time, sf::Vector2f&);
	void Seek(sf::Vector2f&);

	// Worker Variables
	sf::Vector2f m_WorkerVelocity;
	sf::Vector2f m_Workerposition;

	sf::Texture m_WorkerTexture;
	sf::Sprite m_Worker;

	sf::Vector2f wanderTarget = sf::Vector2f(0.0, 0.0);
	float time = 5.0f;

	float distance;
	float radius = 500.0f;
	float m_WorkerOreintation;
};

