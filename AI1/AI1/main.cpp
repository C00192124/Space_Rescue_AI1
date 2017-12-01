#include <iostream>
#include <SFML\Graphics.hpp>
#include "InputManager.h"
#include "Menu.h"
#include "Player.h"

using namespace std;

sf::Event event;
static const int windowWidth = 1024;
static const int windowHeight = 768;

void main()
{
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "AI");
	window.setFramerateLimit(60);

	InputManager *input = new InputManager(event);
	Menu m_Menu(windowWidth, windowHeight, input);
	Player p(input);

	while (window.isOpen())
	{
		//check input
		input->CheckInput(window);

		//Update
		p.Update();
		window.setView(p.GetView());
		m_Menu.Update();

		//draw
		window.clear();
		m_Menu.draw(window);
		p.Render(window);
		window.display();
	}
}