#pragma once
#include "IEntity.h"
#include "IRenderable.h"
#include "IEventHandler.h"
class Tank : public IEntity, public IRenderable, public IEventHandler
{
private:
	int xPosition = 0;
	int yPosition = 0;
	void update(sf::Event event) override;
public:
	Tank(int x, int y) : xPosition(x), yPosition(y) {}

	virtual void draw(sf::RenderWindow& window) = 0;
	void onEvent(sf::Event event) override;
	void publishEvent(sf::Event event) override;

};

