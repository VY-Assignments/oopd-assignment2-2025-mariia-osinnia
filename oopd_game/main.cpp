#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "Renderer.h"
#include "EntityManager.h"
#include "EventManager.h"
#include "TankFactory.h"
#include "InteractiveObjectFactory.h"
#include "EventType.h"
#include "CollisionManager.h"

int main() {
	int windowWidth = 1280, windowHeight = 720;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Tanks Game");
	sf::Clock clock;

	EntityManager entityManager;
	EventManager eventManager;
	Renderer renderer(window, entityManager, eventManager);

	TankFactory tankF(entityManager, eventManager);
	InteractiveObjectFactory interactiveObjectF;
	IEntityFactory& tankFactory = tankF;
	IEntityFactory& interactiveObjectFactory = interactiveObjectF;

	GameManager gameManager(eventManager, entityManager, tankFactory, interactiveObjectFactory);
	CollisionManager collisionManager(entityManager);

	sf::Event event;

	while (window.isOpen()) {
		float deltaTime = clock.restart().asSeconds();
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			renderer.handleInput(event);
		}

		gameManager.update(deltaTime);
		entityManager.updateAll(deltaTime);
		collisionManager.checkCollision();
		renderer.getRenderable();
		renderer.draw();
	}

	return 0;
}