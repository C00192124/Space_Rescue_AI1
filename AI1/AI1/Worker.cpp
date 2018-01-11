#include "Worker.h"


Worker::Worker()
{
	m_WorkerTexture.loadFromFile("Resources/butterfly.png");
	m_Worker.setTexture(m_WorkerTexture);
	m_WorkerVelocity = sf::Vector2f(3.0f, 0.0f);
	m_WorkerPosition = sf::Vector2f(rand() % 3000, rand() % 3000);
	m_Worker.setOrigin(m_Worker.getLocalBounds().width / 2, m_Worker.getLocalBounds().height / 2);
	distance = 1000;
}

Worker::~Worker() {}

void Worker::Render(sf::RenderWindow &w)
{
	w.draw(m_Worker);
}

void Worker::Update(GameWorld &w)
{	
	
	Functions::Wander(time, wanderTarget,m_WorkerPosition,m_WorkerVelocity,radius, distance,m_WorkerOrientation,m_Worker);

	m_WorkerPosition += m_WorkerVelocity;
	m_Worker.setPosition(m_WorkerPosition);

	for (int i = 0; i < 48; i++)
	{
		for (int j = 0; j < 48; j++)
		{
			if (w.world[j][i] == 2 || w.world[j][i] == 0)
			{
				if ((m_WorkerPosition.x + 32 >= (64 * i) - 32)
					&& (m_WorkerPosition.x - 32 <= ((64 * i) + 64 + 32))
					&& (m_WorkerPosition.y + 32 >= (64 * j) - 32)
					&& (m_WorkerPosition.y - 32 <= ((64 * j) + 64 + 32)))
				{
					m_WorkerVelocity = -m_WorkerVelocity;
					//std::cout << "Hit" << std::endl;
				}
			}
		}
	}
	
	/*if (m_WorkerPosition.x + 32 <= 64 + 32)
	{
		m_WorkerVelocity = -m_WorkerVelocity;
	}

	if (m_WorkerPosition.x + 32 >= 3008 - 32)
	{
		m_WorkerVelocity = -m_WorkerVelocity;
	}
	
	if (m_WorkerPosition.y + 32 <= 64 + 32)
	{
		m_WorkerVelocity = -m_WorkerVelocity;
	}
	
	if (m_WorkerPosition.y + 32 >= 3008 - 32)
	{
		m_WorkerVelocity = -m_WorkerVelocity;
	}*/
	
}

