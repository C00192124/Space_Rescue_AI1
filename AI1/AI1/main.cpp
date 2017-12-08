#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "InputManager.h"
#include "Menu.h"
#include "Player.h"
#include "Gamestates.h"
#include "GameWorld.h"

using namespace std;

sf::Event event;
static const int windowWidth = 1024;
static const int windowHeight = 768;
gamestates m_state;
void main()
{
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "AI");
	window.setFramerateLimit(60);


	m_state.currentState = gamestates::Menu;

	InputManager *input = new InputManager(event);
	GameWorld world;
	Menu m_Menu(windowWidth, windowHeight, input);
	Player p(input);

	while (window.isOpen())
	{
		//check input
		input->CheckInput(window);

		//Update
		if (m_state.currentState == gamestates::Play)
		{
			p.Update();
			window.setView(p.GetView());
		}
		else if (m_state.currentState == gamestates::Menu)
		{
			m_Menu.Update();
		}
		//Method to change the game states in the menu.
		m_Menu.SelectedItem(&m_state,window);
		//draw
		window.clear();
		if (m_state.currentState == gamestates::Play)
		{
			world.Render(window);
			p.Render(window);
		}
		else if (m_state.currentState == gamestates::Menu)
		{
			m_Menu.draw(window);
		}
		window.display();
	}
}