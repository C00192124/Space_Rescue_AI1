#include "AlienNest.h"



AlienNest::AlienNest()
{
	m_NestTexture.loadFromFile("Resources/beehive.png");
	m_Nest.setTexture(m_NestTexture);
	m_Nest.setOrigin(m_Nest.getLocalBounds().width / 2, m_Nest.getLocalBounds().height / 2);
	m_Nest.setPosition(1500,1500);
	m_MaxNests = 3;

}


AlienNest::~AlienNest()
{
}

void AlienNest::Update()
{

}

void AlienNest::Render(sf::RenderWindow &w)
{
		w.draw(m_Nest);
	
	
}
