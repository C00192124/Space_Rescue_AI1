#include "Player.h"

Player::Player()
{

}

Player::Player(InputManager *i)
{
	m_PlayerTexture.loadFromFile("Resources/player.png");
	m_Player.setTexture(m_PlayerTexture);
	m_Player.setOrigin(m_Player.getLocalBounds().width / 2, m_Player.getLocalBounds().height / 2);
	m_Player.setPosition(1500, 1500);
	camera = sf::View(sf::FloatRect(0, 0, 1024, 768));
	m_Input = i;
}

void Player::Render(sf::RenderWindow &w)
{
	w.draw(m_Player);
}

void Player::Update(std::vector<Worker> *w, std::vector<PowerUp> *pUp)
{
	m_Velocity = Functions::setVelocity(m_Orientation);
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

	if (powerUpBool)
	{
		powerUpTimer--;
		if (powerUpTimer > 0)
		{
			m_Speed = 7.5;
		}
		else
		{
			m_Speed = 5.0;
			powerUpTimer = 180;
			powerUpBool = false;

		}
	}

	Collision(w, pUp);
}

void Player::Collision(std::vector<Worker> *w, std::vector<PowerUp> *pUp)
{
	// Worker Collision
	for (int i = 0; i < w->size(); i++)
	{
		if (((m_Player.getPosition().x + 32) > w->at(i).m_Worker.getPosition().x - 32)
			&& ((m_Player.getPosition().y + 32) > w->at(i).m_Worker.getPosition().y - 32)
			&& ((m_Player.getPosition().x - 32) < w->at(i).m_Worker.getPosition().x + 32)
			&& ((m_Player.getPosition().y - 32) < w->at(i).m_Worker.getPosition().y + 32))
		{
			w->erase(w->begin() + i);
		}
		
	}

	// PowerUp Collision
	for (int i = 0; i < pUp->size(); i++)
	{
		if (((m_Player.getPosition().x + 32) > pUp->at(i).m_PowerUp.getPosition().x - 32)
			&& ((m_Player.getPosition().y + 32) > pUp->at(i).m_PowerUp.getPosition().y - 32)
			&& ((m_Player.getPosition().x - 32) < pUp->at(i).m_PowerUp.getPosition().x + 32)
			&& ((m_Player.getPosition().y - 32) < pUp->at(i).m_PowerUp.getPosition().y + 32))
		{
			pUp->erase(pUp->begin() + i);
			powerUpBool = true;
		}

	}
}

sf::View Player::GetView()
{
	return camera;
}

Player::~Player() {}