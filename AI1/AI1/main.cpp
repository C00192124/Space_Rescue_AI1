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
#include "Sweeper.h"

using namespace std;

sf::Event event;
static const int windowWidth = 1024;
static const int windowHeight = 768;
gamestates m_state;

void main()
{
	TextureLoader * TextureManager;
	TextureManager = TextureLoader::Instance();
	TextureManager->addTexture("Worker", "Resources/butterfly.png");
	TextureManager->addTexture("PowerUp", "Resources/Lightningbolt.png");
	TextureManager->addTexture("Bullet", "Resources/pb.png");

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "AI");
	window.setFramerateLimit(60);
	srand(time(NULL));

	m_state.currentState = gamestates::Menu;

	InputManager *input = new InputManager(event);
	GameWorld world;
	Menu m_Menu(windowWidth, windowHeight, input);
	Sweeper sweeper;

	vector<Worker> workers;
	Worker worker;
	for (int i = 0; i < 10; i++)
	{
		worker = Worker();
		workers.push_back(worker);
	}

	AlienNest m_aNest;
	vector<AlienNest> nest;
	for (int i = 0; i < 3; i++)
	{
		m_aNest = AlienNest();
		nest.push_back(m_aNest);
	}
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
			p.Update(&workers, &powerups, &nest);
			sweeper.Update(world, p.m_Player, workers);

			for (int i = 0; i < workers.size(); i++)
			{
				workers.at(i).Update(world);
			}

			for (int i = 0; i < nest.size(); i++)
			{
				nest.at(i).Update(p.m_Player);
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

			for (int i = 0; i < nest.size(); i++)
			{
				nest.at(i).Render(window);
			}

			sweeper.Render(window);
			p.Render(window);

		}
		else if (m_state.currentState == gamestates::Menu)
		{
			m_Menu.draw(window);
		}
		window.display();
	}
}