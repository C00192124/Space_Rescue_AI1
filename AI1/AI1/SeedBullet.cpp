#include "SeedBullet.h"



SeedBullet::SeedBullet(sf::Vector2f& p,sf::Vector2f& pVelocity, float& ori)
{
	//m_TLoader = TextureLoader::Instance();
	m_bullet.loadFromFile("Resources/pb.png");
	//m_bullet = m_TLoader->getTexture("Bullet");

	m_sprite.setTexture(m_bullet);
	m_velocity = pVelocity;
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);
	m_sprite.setPosition(p);
	m_speed = 8.5;
	orientation = ori;
}


SeedBullet::~SeedBullet()
{
}
bool SeedBullet::Update()
{
	timer--;
	if (timer < 0)
	{
		return false;
		
	}

	m_velocity = Functions::setVelocity(orientation);
	m_velocity *= m_speed;
	m_sprite.move(m_velocity);
}

void SeedBullet::Render(sf::RenderWindow &w)
{
	w.draw(m_sprite);
}