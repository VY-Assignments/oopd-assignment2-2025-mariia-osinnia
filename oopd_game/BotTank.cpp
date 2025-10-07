#include "BotTank.h"

void BotTank::draw(sf::RenderWindow& window)
{
	sf::RectangleShape rectangle({ 10, 10 });
	rectangle.setPosition(10, 10);
	rectangle.setFillColor(sf::Color::Red);
	window.draw(rectangle);
}
