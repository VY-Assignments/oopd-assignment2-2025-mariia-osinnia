#include "BotTank.h"


void BotTank::publishEvent(EventType& event)
{
}

void BotTank::update(float deltaTime)
{
}

RenderData BotTank::getRenderData() const
{
    RenderData renderData;
    renderData.position = getPosition();
    renderData.size = getSize();
    renderData.color = color;
    renderData.shape = sprite;
    renderData.rotation = getRotation();
    return renderData;
}

void BotTank::onEvent(const EventType & event)
{
}
