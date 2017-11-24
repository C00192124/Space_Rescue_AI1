#pragma once
#include "InputManager.h"
#include <iostream>
using namespace std;

InputManager::InputManager(sf::Event e)
{
	m_event = e;
}

void InputManager::CheckInput(sf::RenderWindow &w)
{
	while (w.pollEvent(m_event))
	{
		switch (m_event.type)
		{
		case sf::Event::Closed:
			w.close();
			break;

		case sf::Event::KeyPressed:
			if (m_event.key.code == sf::Keyboard::Down) {
				down = true;
				cout << "Down Pressed" << endl;
			}
			if (m_event.key.code == sf::Keyboard::Up) {
				up = true;
				cout << "Up Pressed" << endl;
			}
			if (m_event.key.code == sf::Keyboard::Left) {
				left = true;
				cout << "Left Pressed" << endl;
			}
			if (m_event.key.code == sf::Keyboard::Right) {
				right = true;
				cout << "Right Pressed" << endl;
			}
			if (m_event.key.code == sf::Keyboard::Space) {
				space = true;
				cout << "Space Pressed" << endl;
			}
			break;

		case sf::Event::KeyReleased:

			if (m_event.key.code == sf::Keyboard::Down)
				down = false;
			if (m_event.key.code == sf::Keyboard::Up)
				up = false;
			if (m_event.key.code == sf::Keyboard::Left)
				left = false;
			if (m_event.key.code == sf::Keyboard::Right)
				right = false;
			if (m_event.key.code == sf::Keyboard::Space)
				space = false;
			break;

		default:
			break;
		}
		
	}
}

InputManager::~InputManager() {}
