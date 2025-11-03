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
	int windowWidth = 960, windowHeight = 720;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Tanks Game");
	sf::Clock clock;

	Map map;
	EntityManager entityManager;
	EventManager eventManager;
	Renderer renderer(window, entityManager, eventManager, map);

	TankFactory tankF(entityManager, eventManager);
	InteractiveObjectFactory interactiveObjectF;
	IEntityFactory& tankFactory = tankF;
	IEntityFactory& interactiveObjectFactory = interactiveObjectF;

	GameManager gameManager(eventManager, entityManager, tankFactory, interactiveObjectFactory, &map);
	CollisionManager collisionManager(entityManager, map);

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

		renderer.getRenderable();
		renderer.draw();

		entityManager.updateAll(deltaTime);
		collisionManager.checkCollision();
		if (gameManager.getShouldReset()) {
			gameManager.reset();
			gameManager.setShouldReset(false);
		}
	}

	return 0;
}