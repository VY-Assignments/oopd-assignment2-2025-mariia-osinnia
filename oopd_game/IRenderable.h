#pragma once
class IRenderable {
public:
	virtual void draw(sf::RenderWindow& window) = 0;
};