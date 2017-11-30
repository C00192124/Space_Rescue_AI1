#pragma once
#include <SFML\Graphics.hpp>
class Player
{
public:
	Player();
	~Player();
	void Render();
	void Update();


private:
	//Player Variables
	sf::Texture m_PlayerTextur;
	sf::Sprite m_Player;
};

