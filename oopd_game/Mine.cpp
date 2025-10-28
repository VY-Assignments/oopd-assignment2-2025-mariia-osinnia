#include "Mine.h"
#include "Tank.h"

void Mine::onEvent(const EventType & event)
{
}

void Mine::publishEvent(const EventType& event)
{
}


void Mine::interact(Tank* tank)
{
	tank->takeDamage(damage);
}

RenderData Mine::getRenderData() const
{
    RenderData renderData;
    renderData.position = getPosition();
    renderData.size = getSize();
    renderData.color = color;
    renderData.shape = sprite;
    renderData.rotation = getRotation();
    return renderData;
}
