#pragma once
#include <SFML/Graphics.hpp>
#include "EntityManager.h"
#include "IRenderable.h"
class Renderer
{
private:
	sf::RenderWindow& window;
	EntityManager& entityManager;
	std::vector<IRenderable*> renderable;
public:
	Renderer(sf::RenderWindow& win, EntityManager& entityM) : window(win), entityManager(entityM) {}
	void draw();
	void drawFrame(const RenderData& renderData, sf::RenderWindow& window);
	void getRenderable();
    void drawVictoryScreen();
	void drawGameOverScreen();
};

