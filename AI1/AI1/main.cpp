#include <iostream>
#include <SFML\Graphics.hpp>
#include "InputManager.h"

using namespace std;

sf::Event event;

void main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "AI");
	window.setFramerateLimit(60);
	InputManager *input = new InputManager(event);

	while (window.isOpen())
	{
		//check input
		input->CheckInput(window);

		//draw
		window.clear();
		
		window.display();
	}
}