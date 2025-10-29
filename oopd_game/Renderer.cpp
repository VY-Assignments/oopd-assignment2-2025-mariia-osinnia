#include "Renderer.h"
#include "IRenderable.h"

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
	if (renderData.shape == "rectangle") {
		sf::RectangleShape rect;
		rect.setOrigin(renderData.size.x / 2, renderData.size.y / 2);
		rect.setPosition(renderData.position.x, renderData.position.y);
		rect.setSize({ renderData.size.x, renderData.size.y });
		std::string color = renderData.color;
		if (color == "yellow"){
			rect.setFillColor(sf::Color::Yellow);
		}
		else if (color == "green") {
			rect.setFillColor(sf::Color::Green);
		}
		else if (color == "pink") {
			rect.setFillColor(sf::Color::Magenta);
		}
		else if (color == "blue") {
			rect.setFillColor(sf::Color::Blue);
		}
		rect.setRotation(renderData.rotation);
		window.draw(rect);
	}
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
	const auto& entities = entityManager.getEntities();
	for (const auto& e : entities) {
		if (IRenderable* r = dynamic_cast<IRenderable*>(e.get())) {
			renderable.push_back(r);
		}
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


