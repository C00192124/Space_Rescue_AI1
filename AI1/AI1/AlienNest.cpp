#include "AlienNest.h"



AlienNest::AlienNest()
{
	m_NestTexture.loadFromFile("Resources/beehive.png");
	m_Nest.setTexture(m_NestTexture);

	m_MissileTexture.loadFromFile("Resources/Stinger.png");
	m_Missile.setTexture(m_MissileTexture);

	m_MissileVelocity = sf::Vector2f(30.0f, 0.0f);

	m_Missile.setOrigin(m_Missile.getLocalBounds().width/2, m_Missile.getLocalBounds().height/2 );
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

void AlienNest::FindPlayerPosition(int x, int y)
{
	m_NestPosition = m_Nest.getPosition();
	sf::Vector2f p = sf::Vector2f(x, y);
	if (!m_FoundPlayer)
	{
		sf::Vector2f m_PositionDifference = m_NestPosition - p;
		m_TotalDistance = Functions::Length(m_PositionDifference);

		if (m_TotalDistance <= m_FiringRange)
		{
			m_FoundPlayer = true;
			std::cout << "Player Found" << std::endl;
		}
		else
		{
			m_FoundPlayer = false;
		}
	}
}

void AlienNest::FireStinger(int x, int y)
{
	sf::Vector2f p = sf::Vector2f(x, y);
	m_NestPosition = m_Nest.getPosition();

	if (m_FoundPlayer)
	{
		m_MissileAlive = true;
		sf::Vector2f MissilePosition = p - m_NestPosition;
		MissilePosition = Functions::Normalise(MissilePosition);
	}
}
void AlienNest::CheckPlayerCollision(sf::Sprite &p)
{

	if(((m_Missile.getPosition().x+16)>p.getPosition().x - 32)
		&&((m_Missile.getPosition().y + 32) > p.getPosition().y - 32)
		&&((m_Missile.getPosition().x - 16) < p.getPosition().x + 32)
		&& ((m_Missile.getPosition().y -32) < p.getPosition().y + 32))
	{
		m_MissileAlive = false;
		m_PlayerHit = true;
		if (m_MissileAlive)
		{
			std::cout << "Missile Hit" << std::endl;
		}
		
	}
}

void AlienNest::Update(sf::Sprite &p)
{
	FindPlayerPosition(p.getPosition().x,p.getPosition().y);
	FireStinger(p.getPosition().x, p.getPosition().y);
	CheckPlayerCollision(p);

	if (m_MissileAlive)
	{
		sf::Vector2f temp = p.getPosition();
		if (m_MissileLifeTime > 0)
		{
			Functions::Seek(temp, m_MissilePosition, m_MissileVelocity, m_MissileOrientation, m_Missile);
			
		}	

		m_MissileLifeTime--;
		m_MissilePosition += m_MissileVelocity;
		m_Missile.setPosition(m_MissilePosition);
	}

	if ((m_FoundPlayer && m_MissileLifeTime <= 0) ||( m_PlayerHit) )
	{
		m_MissileAlive = false;
		m_FoundPlayer = false;
		m_PlayerHit = false;
		m_MissileLifeTime = 300;
		m_MissilePosition = m_NestPosition;
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
