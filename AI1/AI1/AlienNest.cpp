#include "AlienNest.h"



AlienNest::AlienNest()
{
	m_NestTexture.loadFromFile("Resources/beehive.png");
	m_Nest.setTexture(m_NestTexture);

	m_MissileTexture.loadFromFile("Resources/Stinger.png");
	m_Missile.setTexture(m_MissileTexture);

	m_MissileVelocity = sf::Vector2f(5.0f, 5.0f);

	m_Missile.setOrigin(m_Missile.getLocalBounds().width, m_Missile.getLocalBounds().height/2 );
	m_Nest.setOrigin(m_Nest.getLocalBounds().width / 2, m_Nest.getLocalBounds().height / 2);

	randx = rand() % 2600;
	randy = rand() % 2600;

	m_Nest.setPosition(randx, randy);

	m_MissilePosition = m_Nest.getPosition();
	m_Missile.setPosition(m_MissilePosition);

	m_MissileAlive = false;

	m_nestAlive = true;
	m_nestHealth = 4;
	m_MissileOrientation = 0.0f;
	m_MissileLifeTime = 300;

	m_FiringRange = 300;

	m_FoundPlayer = false;
}


AlienNest::~AlienNest()
{
}

void AlienNest::FindPlayer(int x, int y)
{
	m_NestPosition = m_Nest.getPosition();
	sf::Vector2f p = sf::Vector2f(x, y);
	if (!m_FoundPlayer)
	{
		sf::Vector2f m_PositionDifference = m_NestPosition - p;
		m_TotalDistance = Vector::Length(m_PositionDifference);

		if (m_TotalDistance <= m_FiringRange)
		{
			m_FoundPlayer = true;
			std::cout << "Player Found" << std::endl;
		}
	}
}

void AlienNest::FireMissile(int x, int y)
{
	sf::Vector2f p = sf::Vector2f(x, y);
	m_NestPosition = m_Nest.getPosition();

	if (m_FoundPlayer)
	{
		m_MissileAlive = true;
		sf::Vector2f MissilePosition = p - m_NestPosition;
		MissilePosition = Vector::Normalise(MissilePosition);
	}
}

void AlienNest::Seek(sf::Vector2f&  tar)
{

	m_MissileVelocity = tar - m_MissilePosition;
	m_MissileVelocity = Vector::Normalise(m_MissileVelocity);
	m_MissileVelocity = m_MissileVelocity * 2.0f;
	m_MissileOrientation = Vector::GetOrientation(m_MissileOrientation, m_MissileVelocity);
	m_Missile.setRotation(m_MissileOrientation);
}

void AlienNest::Update(sf::Sprite &p)
{
	FindPlayer(p.getPosition().x,p.getPosition().y);
	FireMissile(p.getPosition().x, p.getPosition().y);
	if (m_MissileAlive)
	{
		sf::Vector2f temp = p.getPosition();
		if (m_MissileLifeTime > 0)
		{
			Seek(temp);
		}	

		m_MissileLifeTime--;
		m_MissilePosition += m_MissileVelocity;
		m_Missile.setPosition(m_MissilePosition);
	}

	if (m_MissileLifeTime < 0)
	{
		m_MissileAlive = false;
		m_MissileLifeTime = 0;
		std::cout << "MissileAlive Set To False" << std::endl;
	}

	if (m_nestHealth == 0)
	{
		m_nestAlive = false;
	}

}

void AlienNest::Render(sf::RenderWindow &w)
{
	if (m_nestAlive)
	{
		w.draw(m_Nest);
	}
		
	if (m_MissileAlive)
	{
		w.draw(m_Missile);
	}
}
