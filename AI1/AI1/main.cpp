#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "InputManager.h"
#include "Menu.h"
#include "Player.h"
#include "Gamestates.h"
#include "GameWorld.h"
#include "Worker.h"
#include "PowerUp.h"
#include "AlienNest.h"
#include "TextureLoader.h"

using namespace std;

sf::Event event;
static const int windowWidth = 1024;
static const int windowHeight = 768;
gamestates m_state;

void main()
{
	TextureLoader * WhiteSquareRemover;
	WhiteSquareRemover = TextureLoader::Instance();
	WhiteSquareRemover->addTexture("Worker", "Resources/butterfly.png");
	WhiteSquareRemover->addTexture("PowerUp", "Resources/Lightningbolt.png");

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "AI");
	window.setFramerateLimit(60);
	srand(time(NULL));

	m_state.currentState = gamestates::Menu;

	InputManager *input = new InputManager(event);
	GameWorld world;
	Menu m_Menu(windowWidth, windowHeight, input);
	
	vector<Worker> workers;
	Worker worker;
	for (int i = 0; i < 10; i++)
	{
		worker = Worker();
		workers.push_back(worker);
	}

	AlienNest m_aNest;
	AlienNest m_aNest1;
	AlienNest m_aNest2;
	Player p(input);

	vector<PowerUp> powerups;
	PowerUp powerup;

	for (int i = 0; i < 4; i++)
	{
		powerup = PowerUp();
		powerups.push_back(powerup);
	}



	while (window.isOpen())
	{
		//check input
		input->CheckInput(window);

		//Update
		if (m_state.currentState == gamestates::Play)
		{
			p.Update(&workers, &powerups);
			m_aNest.Update(p.m_Player);
			m_aNest1.Update(p.m_Player);
			m_aNest2.Update(p.m_Player);

			for (int i = 0; i < powerups.size(); i++)
			{
				powerups.at(i).Update();
			}

			for (int i = 0; i < workers.size(); i++)
			{
				workers.at(i).Update(world);
			}
			window.setView(p.GetView());
		}

		else if (m_state.currentState == gamestates::Menu)
		{
			m_Menu.Update();
		}
		//Method to change the game states in the menu.
		m_Menu.SelectedItem(&m_state, window);
		
		//draw
		window.clear();
		if (m_state.currentState == gamestates::Play)
		{
			world.Render(window);

			for (int i = 0; i < powerups.size(); i++)
			{
				powerups.at(i).Render(window);
			}
			
			for (int i = 0; i < workers.size(); i++)
			{
				workers.at(i).Render(window);
			}
			m_aNest.Render(window);
			m_aNest1.Render(window);
			m_aNest2.Render(window);
			p.Render(window);

		}
		else if (m_state.currentState == gamestates::Menu)
		{
			m_Menu.draw(window);
		}
		window.display();
	}
}