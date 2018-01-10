#include "AlienNest.h"



AlienNest::AlienNest()
{
	m_NestTexture.loadFromFile("Resources/beehive.png");
	m_Nest.setTexture(m_NestTexture);
	m_Nest.setOrigin(m_Nest.getLocalBounds().width / 2, m_Nest.getLocalBounds().height / 2);

	randx = rand() % 3000;
	randy = rand() % 3000;

	m_Nest.setPosition(randx, randy);
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
