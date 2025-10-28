#include "HealthPack.h"
#include "Tank.h"

void HealthPack::onEvent(const EventType & event)
{
}

void HealthPack::publishEvent(const EventType& event)
{
}

void HealthPack::interact(Tank* tank)
{
	tank->heal(healthBonus);
}

RenderData HealthPack::getRenderData() const
{
    RenderData renderData;
    renderData.position = getPosition();
    renderData.size = getSize();
    renderData.color = color;
    renderData.shape = sprite;
    renderData.rotation = getRotation();
    return renderData;
}
