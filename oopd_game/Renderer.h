#pragma once
#include <SFML/Graphics.hpp>
#include "EntityManager.h"
#include "EventManager.h"
#include "IRenderable.h"
class Renderer
{
private:
	sf::RenderWindow& window;
	EntityManager& entityManager;
	EventManager& eventManager;
	std::vector<IRenderable*> renderable;
public:
	Renderer(sf::RenderWindow& win, EntityManager& entityM, EventManager& eventM) : window(win), 
		entityManager(entityM), eventManager(eventM) {}
	void draw();
	void drawFrame(const RenderData& renderData, sf::RenderWindow& window);
	void handleInput(sf::Event& event);
	void getRenderable();
    void drawVictoryScreen();
	void drawGameOverScreen();
};

