#include "Worker.h"


Worker::Worker()
{
	m_WorkerTexture.loadFromFile("Resources/Bee.png");
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

void Worker::Update()
{	
	Wander(time,wanderTarget);
	m_WorkerPosition += m_WorkerVelocity;
	m_Worker.setPosition(m_WorkerPosition);
}

void Worker::Wander(float & time, sf::Vector2f& target)
{
	time += 1.0f / 60.0f;

	if (time >= 0.8f)
	{
		time = 0.0;
	}

	if (time == 0.0f)
	{
		sf::Vector2f direction = Vector::Normalise(m_WorkerVelocity);
		sf::Vector2f point = direction*distance;

		point += m_WorkerPosition;
		float angle = ((rand() % 361)*3.14159 / 180);


		float x = radius*sin(angle) + point.x;
		float y = radius*cos(angle) + point.y;

		point = sf::Vector2f(x, y);
		target = point;

	}
	Seek(target);

}

void Worker::Seek(sf::Vector2f&  tar)
{
	m_WorkerVelocity = tar - m_WorkerPosition;
	m_WorkerVelocity = Vector::Normalise(m_WorkerVelocity);
	m_WorkerVelocity = m_WorkerVelocity * 2.0f;
	m_WorkerOrientation= Vector::GetOrientation(m_WorkerOrientation, m_WorkerVelocity);
	m_Worker.setRotation(m_WorkerOrientation);
}
