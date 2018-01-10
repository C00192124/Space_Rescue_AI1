#include "PowerUp.h"



PowerUp::PowerUp()
{
	m_PowerUpTexture.loadFromFile("Resources/Lightningbolt.png");
	m_PowerUp.setTexture(m_PowerUpTexture);
	m_PowerUp.setOrigin(m_PowerUp.getLocalBounds().width / 2, m_PowerUp.getLocalBounds().height / 2);
	m_PowerUp.setPosition(1300,1000);

}


PowerUp::~PowerUp()
{
}

void PowerUp::Render(sf::RenderWindow &w)
{
	w.draw(m_PowerUp);
}

void PowerUp::Update()
{

}

void PowerUp::Collision(Player* p)
{
	
}