#include "Menu.h"



Menu::Menu(float width, float height)
{
	if (!m_MenuTexture.loadFromFile("menuBackground.jpg"))
	{
		
	}

	m_MenuSprite.setTexture(m_MenuTexture);

	if (!m_Font.loadFromFile("arial.ttf"))
	{
		
	}

	m_MenuText[0].setFont(m_Font);
	m_MenuText[0].setFillColor(sf::Color::Magenta);
	m_MenuText[0].setString("Play");
	m_MenuText[0].setCharacterSize(150);
	m_MenuText[0].setPosition(sf::Vector2f(width / 2.5, height / (Max_Number_Of_Items + 1) * 1));

	m_MenuText[1].setFont(m_Font);
	m_MenuText[1].setFillColor(sf::Color::Magenta);
	m_MenuText[1].setString("Exit");
	m_MenuText[1].setCharacterSize(150);
	m_MenuText[1].setPosition(sf::Vector2f(width / 2.5, height / (Max_Number_Of_Items + 1) * 1));

	
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	window.draw(m_MenuSprite);

	for (int i = 0; i < Max_Number_Of_Items; i++)
	{
		window.draw(m_MenuText[i]);
	}
}

//The method changes the colour of the text to highlight the current item selected
void Menu::MoveUp()
{
	if (m_SelectedItem - 1 >= 0)
	{
		m_MenuText[m_SelectedItem].setFillColor(sf::Color::Black);
		m_SelectedItem--;
		m_MenuText[m_SelectedItem].setFillColor(sf::Color::Magenta);
	}
	else if (m_SelectedItem + 1 < Max_Number_Of_Items)
	{
		m_MenuText[m_SelectedItem].setFillColor(sf::Color::Black);
		m_SelectedItem += 1;
		m_MenuText[m_SelectedItem].setFillColor(sf::Color::Magenta);

	}
}

void Menu::MoveDown()
{
	if (m_SelectedItem + 1 < Max_Number_Of_Items)
	{
		m_MenuText[m_SelectedItem].setFillColor(sf::Color::Black);
		m_SelectedItem++;
		m_MenuText[m_SelectedItem].setFillColor(sf::Color::Magenta);
	}
	else if (m_SelectedItem - 1 >= 0)
	{
		m_MenuText[m_SelectedItem].setFillColor(sf::Color::Black);
		m_SelectedItem -= 1;
		m_MenuText[m_SelectedItem].setFillColor(sf::Color::Magenta);
	}
}

