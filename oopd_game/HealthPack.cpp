#include "HealthPack.h"
#include "Tank.h"

void HealthPack::onEvent(const EventType & event)
{
}

void HealthPack::publishEvent(EventType& event)
{
}

void HealthPack::update(float deltaTime)
{
}

void HealthPack::interact(Tank* tank)
{
	tank->heal(healthBonus);
}
