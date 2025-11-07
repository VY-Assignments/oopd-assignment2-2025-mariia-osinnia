#include "GameLoop.h"

void GameLoop::run()
{
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
}
