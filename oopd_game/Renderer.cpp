#include "Renderer.h"
#include "IRenderable.h"
#include <iostream>

void Renderer::draw()
{
	window.clear();
	for (auto& obj : renderable) {
		drawFrame(std::move(obj->getRenderData()), window); //@todo learn
	}
	window.display();
}

void Renderer::drawFrame(const RenderData& renderData, sf::RenderWindow& window)
{
	sf::RectangleShape rect;
	rect.setOrigin(renderData.size.x / 2, renderData.size.y / 2);
	rect.setPosition(renderData.position.x, renderData.position.y);
	rect.setSize({ renderData.size.x, renderData.size.y });
	rect.setRotation(renderData.rotation);
	std::string type = renderData.type;
	EntityTypes entityType = stringToEntityType(type);
	switch (entityType) {
		case EntityTypes::PlayerTank:
			rect.setTexture(&playerTankTexture);
			break;
		case EntityTypes::BotTank:
			rect.setTexture(&botTankTexture);
			break;
		case EntityTypes::HealthPack:
			rect.setFillColor(sf::Color::Magenta);
			break;
		case EntityTypes::Mine:
			rect.setFillColor(sf::Color::Blue);
			break;
		case EntityTypes::Obstacle:
			rect.setFillColor(sf::Color::White);
			break;
		case EntityTypes::Projectile:
			rect.setTexture(&projectileTexture);
			break;
		case EntityTypes::Unknown:
			rect.setFillColor(sf::Color::White);
			break;
	}
	window.draw(rect);
}

void Renderer::handleInput(sf::Event& event)
{
	EventType gameEvent = EventType::None;
	if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code) {
		case sf::Keyboard::W: 
			gameEvent = EventType::MovingForward; 
			break;
		case sf::Keyboard::S: 
			gameEvent = EventType::MovingBackward; 
			break;
		case sf::Keyboard::A: 
			gameEvent = EventType::TurnLeft; 
			break;
		case sf::Keyboard::D: 
			gameEvent = EventType::TurnRight; 
			break;
		case sf::Keyboard::Space: 
			gameEvent = EventType::Shoot; 
			break;
		default: break;
		}
	}
	else if (event.type == sf::Event::KeyReleased) {
		switch (event.key.code) {
		case sf::Keyboard::W: 
			gameEvent = EventType::StopForward; 
			break;
		case sf::Keyboard::S: 
			gameEvent = EventType::StopBackward; 
			break;
		case sf::Keyboard::A: 
			gameEvent = EventType::StopTurnLeft; 
			break;
		case sf::Keyboard::D: 
			gameEvent = EventType::StopTurnRight; 
			break;
		default: break;
		}
	}

	if (gameEvent != EventType::None) {
		eventManager.notify(gameEvent);
	}
}

void Renderer::getRenderable()
{
	renderable.clear();
	const std::vector<std::unique_ptr<IEntity>>& entities = entityManager.getEntities();
	for (const auto& entity : entities) {
		if (IRenderable* r = dynamic_cast<IRenderable*>(entity.get())) {
			renderable.push_back(r);
		}
	}
	const std::vector<std::unique_ptr<ICollidable>>& obstacles = map.getObstacles();
	for (const auto& obstacle : map.getObstacles()) {
		IRenderable* r = dynamic_cast<IRenderable*>(obstacle.get());
		renderable.push_back(r);
	}
}

void Renderer::drawVictoryScreen()
{
	window.clear(sf::Color::Green);

	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/arial.ttf");
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::White);
	text.setString("Victory!");
	text.setPosition(400, 300);

	window.draw(text);
	window.display();
}

void Renderer::drawGameOverScreen()
{
	window.clear(sf::Color::Red);

	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/arial.ttf");
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::White);
	text.setString("Game Over!");
	text.setPosition(400, 300);

	window.draw(text);
	window.display();
}

EntityTypes Renderer::stringToEntityType(std::string& type)
{
	if (type == "playerTank") {
		return EntityTypes::PlayerTank;
	}
	else if (type == "botTank") {
		return EntityTypes::BotTank;
	}
	else if (type == "mine") {
		return EntityTypes::Mine;
	}
	else if (type == "healthPack") {
		return EntityTypes::HealthPack;
	}
	else if (type == "obstacle") {
		return EntityTypes::Obstacle;
	}
	else if (type == "projectile") {
		return EntityTypes::Projectile;
	}
	else {
		return EntityTypes::Unknown;
	}
}



