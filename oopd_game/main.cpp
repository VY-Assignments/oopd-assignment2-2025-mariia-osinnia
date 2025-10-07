#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "Renderer.h"
#include "EntityManager.h"
#include "EventManager.h"
#include "TankFactory.h"
#include "InteractiveObjectFactory.h"
int main() {
	int windowSize = 300;
	sf::RenderWindow window(sf::VideoMode(windowSize, 300), "Tanks Game");
	
	EntityManager entityManager;
	EventManager eventManager;
	Renderer renderer(window, entityManager);

	TankFactory tankF;
	InteractiveObjectFactory interactiveObjectF;
	IEntityFactory& tankFactory = tankF;
	IEntityFactory& interactiveObjectFactory = interactiveObjectF;

	GameManager gameManager(eventManager, entityManager, tankFactory, interactiveObjectFactory);

	sf::Event event;

	while (window.isOpen()) {
		window.pollEvent(event);
		renderer.draw();
	}
}