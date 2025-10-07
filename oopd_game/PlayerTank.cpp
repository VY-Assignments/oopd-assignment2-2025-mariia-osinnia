#include "PlayerTank.h"

void PlayerTank::draw(sf::RenderWindow& window)
{
	sf::RectangleShape rectangle({ 10, 10 });
	rectangle.setPosition(20, 20);
	rectangle.setFillColor(sf::Color::Green);
	window.draw(rectangle);
}
