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
	sf::RenderWindow window(sf::VideoMode(1024, 768), "AI");
	window.setFramerateLimit(60);
	Menu m_Menu(windowWidth, windowHeight);

	InputManager *input = new InputManager(event);
	Player p(input);

	while (window.isOpen())
	{
		//check input
		input->CheckInput(window);

		//Update
		p.Update();
		window.setView(p.GetView());

		//draw
		window.clear();
		m_Menu.draw(window);
		p.Render(window);
		window.display();
	}
}