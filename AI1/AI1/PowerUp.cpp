#include "PowerUp.h"



PowerUp::PowerUp()
{
	m_TLoader = TextureLoader::Instance();
	m_PowerUpTexture=m_TLoader->getTexture("PowerUp");

	m_PowerUp.setTexture(m_PowerUpTexture);
	m_PowerUp.setOrigin(m_PowerUp.getLocalBounds().width / 2, m_PowerUp.getLocalBounds().height / 2);
	m_PowerUpPosition = sf::Vector2f(rand() % 3000, rand() % 3000);
	m_PowerUp.setPosition(m_PowerUpPosition);

}


PowerUp::~PowerUp()
{
}

void PowerUp::Render(sf::RenderWindow &w)
{
	w.draw(m_PowerUp);
}
