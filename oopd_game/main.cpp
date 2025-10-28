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
	Renderer renderer(window, entityManager);

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

			EventType gameEvent = EventType::None;
			if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code) {
				case sf::Keyboard::W: gameEvent = EventType::MovingForward; break;
				case sf::Keyboard::S: gameEvent = EventType::MovingBackward; break;
				case sf::Keyboard::A: gameEvent = EventType::TurnLeft; break;
				case sf::Keyboard::D: gameEvent = EventType::TurnRight; break;
				case sf::Keyboard::Space: gameEvent = EventType::Shoot; break;
				default: break;
				}
			}
			else if (event.type == sf::Event::KeyReleased) {
				switch (event.key.code) {
				case sf::Keyboard::W: gameEvent = EventType::StopForward; break;
				case sf::Keyboard::S: gameEvent = EventType::StopBackward; break;
				case sf::Keyboard::A: gameEvent = EventType::StopTurnLeft; break;
				case sf::Keyboard::D: gameEvent = EventType::StopTurnRight; break;
				default: break;
				}
			}


			if (gameEvent != EventType::None) {
				eventManager.notify(gameEvent);
			}
		}

		gameManager.update(deltaTime);
		entityManager.updateAll(deltaTime);
		collisionManager.checkCollision();
		renderer.getRenderable();
		renderer.draw();
	}

	return 0;
}