#pragma once
#include <iostream>
#include "InputManager.h"
#include <SFML\Graphics.hpp>

#define Max_Number_Of_Items 2
class Menu
{
public:
	Menu() {}
	Menu(float,float,InputManager*);
	~Menu();
	void draw(sf::RenderWindow &);
	void MoveDown();
	void MoveUp();
	void Update();
	int GetPressedItem() { return m_SelectedItem; }

private:
	sf::Sprite m_MenuSprite;
	sf::Font m_Font;
	sf::Text m_MenuText[Max_Number_Of_Items];
	sf::Texture m_MenuTexture;
	int m_SelectedItem;
	InputManager *input;
	int timer;
};

