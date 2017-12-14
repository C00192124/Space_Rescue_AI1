#include "Worker.h"


Worker::Worker()
{
	m_WorkerTexture.loadFromFile("Resources/Bee.png");
	m_Worker.setTexture(m_WorkerTexture);
	m_WorkerVelocity = sf::Vector2f(3.0f, 0.0f);
	m_Workerposition = sf::Vector2f(1200, 1500);
	m_Worker.setOrigin(m_Worker.getLocalBounds().width / 2, m_Worker.getLocalBounds().height / 2);
	distance = 75;

}


Worker::~Worker()
{
}

void Worker::Render(sf::RenderWindow &w)
{
	w.draw(m_Worker);
}

float Worker::length(sf::Vector2f vec)
{
	float ans = sqrtf(pow(vec.x, 2) + pow(vec.y, 2));

	return ans;
}

sf::Vector2f Worker::Normalise(sf::Vector2f vec)
{
	float length = sqrtf(pow(vec.x, 2) + pow(vec.y, 2));
	sf::Vector2f ans = sf::Vector2f(vec.x / length, vec.y / length);
	return ans;
}

void Worker::MoveWorker()
{
	m_Workerposition += m_WorkerVelocity;
	m_Worker.setPosition(m_Workerposition);
}

void Worker::update()
{	
	Wander(time,wanderTarget);
	MoveWorker();

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
		sf::Vector2f direction = Normalise(m_WorkerVelocity);
		sf::Vector2f point = direction*distance;

		point += m_Workerposition;
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
	m_WorkerVelocity = tar - m_Workerposition;
	m_WorkerVelocity = Normalise(m_WorkerVelocity);
	m_WorkerVelocity = m_WorkerVelocity * 2.0f;
	m_WorkerOreintation= GetOreintation();
	m_Worker.setRotation(m_WorkerOreintation);

}

float Worker::GetOreintation()
{
	float rotation = 0.0f;
	if (length(m_WorkerVelocity) > 0) {
		// Note atan2 returns an angle in radians which you 
		// may want to convert to degrees.
		rotation = atan2(m_WorkerVelocity.x, -m_WorkerVelocity.y);

		rotation = rotation * 180 / 3.14;

	}
	return rotation;
}