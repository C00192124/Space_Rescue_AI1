#pragma once
#include <SFML\Graphics.hpp>

#define Max_Number_Of_Items 3
class Menu
{
public:
	Menu(float,float);
	~Menu();
	void draw(sf::RenderWindow &);
	void MoveDown();
	void MoveUp();
	int GetPressedItem() { return m_SelectedItem; }

private:
	sf::Sprite m_MenuSprite;
	sf::Font m_Font;
	sf::Text m_MenuText[Max_Number_Of_Items];
	sf::Texture m_MenuTexture;
	int m_SelectedItem;
};

