#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "Renderer.h"
#include "EntityManager.h"
#include "EventManager.h"
#include "TankFactory.h"
#include "InteractiveObjectFactory.h"
#include "EventType.h"
int main() {
	int windowWidth = 1280, windowHeight = 720;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Tanks Game");
	sf::Clock clock;

	EntityManager entityManager;
	EventManager eventManager;
	Renderer renderer(window, entityManager);

	TankFactory tankF(entityManager);
	InteractiveObjectFactory interactiveObjectF;
	IEntityFactory& tankFactory = tankF;
	IEntityFactory& interactiveObjectFactory = interactiveObjectF;

	GameManager gameManager(eventManager, entityManager, tankFactory, interactiveObjectFactory);

	sf::Event event;

	while (window.isOpen()) {
		float deltaTime = clock.restart().asSeconds();
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			EventType gameEvent = EventType::None;
			if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
				bool isPressed = event.type == sf::Event::KeyPressed;

				switch (event.key.code) {
				case sf::Keyboard::W: gameEvent = isPressed ? EventType::MovingForward : EventType::Stop; break;
				case sf::Keyboard::S: gameEvent = isPressed ? EventType::MovingBackward : EventType::Stop; break;
				case sf::Keyboard::A: gameEvent = isPressed ? EventType::TurnLeft : EventType::Stop; break;
				case sf::Keyboard::D: gameEvent = isPressed ? EventType::TurnRight : EventType::Stop; break;
				case sf::Keyboard::Space: if (isPressed) gameEvent = EventType::Shoot; break;
				default: break;
				}
			}

			if (gameEvent != EventType::None) {
				eventManager.notify(gameEvent);
			}
		}
		entityManager.updateAll(deltaTime);
		renderer.getRenderable();
		renderer.draw();
	}
}