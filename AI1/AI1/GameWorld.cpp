#include "GameWorld.h"

GameWorld::GameWorld()
{
	grassTex.loadFromFile("Resources/grass.png");
	grass.setTexture(grassTex);
	treeTex.loadFromFile("Resources/tree.png");
	tree.setTexture(treeTex);
	stumpTex.loadFromFile("Resources/stump.png");
	stump.setTexture(stumpTex);
}

void GameWorld::Render(sf::RenderWindow &w)
{
	for (int i = 0; i < 48; i++)
	{
		for (int j = 0; j < 48; j++)
		{
			if (world[j][i] == 1)
			{
				grass.setPosition(sf::Vector2f(i * 64, j * 64));
				w.draw(grass);
			}
			if (world[j][i] == 0)
			{
				tree.setPosition(sf::Vector2f(i * 64, j * 64));
				w.draw(tree);
			}
			if (world[j][i] == 2)
			{
				stump.setPosition(sf::Vector2f(i * 64, j * 64));
				w.draw(stump);
			}

		}
	}
}

GameWorld::~GameWorld() {}