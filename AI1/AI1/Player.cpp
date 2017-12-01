#include "Player.h"

Player::Player(InputManager *i)
{
	m_PlayerTexture.loadFromFile("Resources/player.png");
	m_Player.setTexture(m_PlayerTexture);
	m_Player.setOrigin(m_Player.getLocalBounds().width / 2, m_Player.getLocalBounds().height / 2);
	m_Player.setPosition(200, 200);
	camera = sf::View(sf::FloatRect(0, 0, 1024, 768));
	m_Input = i;
}

void Player::Render(sf::RenderWindow &w)
{
	w.draw(m_Player);
}

void Player::Update()
{
	m_Velocity = setVelocity(m_Orientation);
	m_Velocity *= m_Speed;
	m_Player.move(m_Velocity);
	camera.setCenter(m_Player.getPosition().x, m_Player.getPosition().y);

	if (m_Input->up)
	{
		if (m_Speed <= 5.0f) {
			m_Speed = m_Speed + 0.1f;
		}
	}
	if (m_Input->down)
	{
		if (m_Speed >= 0.1f) {
			m_Speed = m_Speed - 0.1f;
		}
	}
	if (m_Input->left)
	{
		m_Orientation = m_Orientation - 0.1;
		m_Player.setRotation(m_Orientation*(180 / 3.14159));
	}
	if (m_Input->right)
	{
		m_Orientation = m_Orientation + 0.1;
		m_Player.setRotation(m_Orientation*(180 / 3.14159));
	}
}

sf::Vector2f Player::setVelocity(float &currentOrientation) {

	sf::Vector2f tempVel;
	tempVel.x = sin(currentOrientation);
	tempVel.y = -cos(currentOrientation);
	return tempVel;
}

sf::View Player::GetView()
{
	return camera;
}

Player::~Player() {}