#pragma once
#include <SFML/Graphics.hpp>
class IEntity {
	virtual void update(sf::Event event) = 0;
};
