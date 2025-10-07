#pragma once
#include <SFML/Graphics.hpp>
class IEventHandler {
	virtual void onEvent(sf::Event event) = 0;
	virtual void publishEvent(sf::Event event) = 0;
};