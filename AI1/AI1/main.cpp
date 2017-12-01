#include <iostream>
#include <SFML\Graphics.hpp>
#include "InputManager.h"
#include "Menu.h"

using namespace std;

sf::Event event;
static const int windowWidth = 1024;
static const int windowHeight = 768;

void main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "AI");
	window.setFramerateLimit(60);

	InputManager *input = new InputManager(event);
	Menu m_Menu(windowWidth, windowHeight, input);

	while (window.isOpen())
	{
		//check input
		input->CheckInput(window);
		m_Menu.Update();

		//draw
		window.clear();
		m_Menu.draw(window);
		window.display();
	}
}