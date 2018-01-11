#include "Sweeper.h"

Sweeper::Sweeper()
{
	m_SweeperTexture.loadFromFile("Resources/dragonfly.png");
	m_Sweeper.setTexture(m_SweeperTexture);
	m_SweeperVelocity = sf::Vector2f(3.0f, 0.0f);
	m_SweeperPosition = sf::Vector2f(1500, 1500);
	m_Sweeper.setOrigin(m_Sweeper.getLocalBounds().width / 2, m_Sweeper.getLocalBounds().height / 2);
	distance = 1000;
	attack = false;
	wander = true;
	flee = false;
}

void Sweeper::Render(sf::RenderWindow &w)
{
	w.draw(m_Sweeper);
}

void Sweeper::Update(GameWorld &w, sf::Sprite &p, vector<Worker> t)
{
	if (!attack)
	{
		for (int q = 0; q < t.size(); q++)
		{
			if (CheckRange(t.at(q).m_Worker.getPosition().x, t.at(q).m_Worker.getPosition().y))
			{
				temp = t.at(q).m_Worker.getPosition();
				prey = q;
				wander = false;
				flee - false;
				attack = true;
			}
		}
	}

	if (wander)
	{
		Functions::Wander(time, wanderTarget, m_SweeperPosition, m_SweeperVelocity, radius, distance, m_SweeperOrientation, m_Sweeper);
	}
	if (attack)
	{
		temp = t.at(prey).m_Worker.getPosition();
		Functions::Seek(temp, m_SweeperPosition, m_SweeperVelocity, m_SweeperOrientation, m_Sweeper);
		if (Collision(t.at(prey).m_Worker))
		{
			t.erase(t.begin() + prey);
			attack = false;
			flee = false;
			wander = true;
		}
	}

	m_SweeperPosition += m_SweeperVelocity;
	m_Sweeper.setPosition(m_SweeperPosition);

	for (int i = 0; i < 48; i++)
	{
		for (int j = 0; j < 48; j++)
		{
			if (w.world[j][i] == 2 || w.world[j][i] == 0)
			{
				if ((m_SweeperPosition.x + 64 >= (64 * i) - 64)
					&& (m_SweeperPosition.x - 64 <= ((64 * i) + 64 + 64))
					&& (m_SweeperPosition.y + 64 >= (64 * j) - 64)
					&& (m_SweeperPosition.y - 64 <= ((64 * j) + 64 + 64)))
				{
					m_SweeperVelocity = -m_SweeperVelocity;
					std::cout << "Hit" << std::endl;
				}
			}
		}
	}
}

bool Sweeper::Collision(sf::Sprite &s)
{
	if (((m_SweeperPosition.x + 48) > s.getPosition().x - 32)
		&& ((m_SweeperPosition.y + 48) > s.getPosition().y - 32)
		&& ((m_SweeperPosition.x - 48) < s.getPosition().x + 32)
		&& ((m_SweeperPosition.y - 48) < s.getPosition().y + 32))
	{
		return true;
	}
	else return false;
}

bool Sweeper::CheckRange(int x, int y)
{
	sf::Vector2f target(x, y);
	sf::Vector2f diff = m_SweeperPosition - target;
	float dist = Functions::Length(diff);
	if (dist <= range)
	{
		return true;
	}
	else return false;
}

Sweeper::~Sweeper() {}