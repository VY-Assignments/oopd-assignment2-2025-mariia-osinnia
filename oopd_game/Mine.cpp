#include "Mine.h"
#include "Tank.h"

void Mine::onEvent(const EventType & event)
{
}

void Mine::publishEvent(EventType& event)
{
}

void Mine::update(float deltaTime)
{
}

void Mine::interact(Tank* tank)
{
	tank->takeDamage(damage);
}
