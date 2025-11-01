#include "BotTank.h"
#include "EventType.h"
#include "EntityManager.h"

void BotTank::publishEvent(const EventType& event)
{
    EventManager& eventManager = getEventManager();
    eventManager.notify(event);
}

void BotTank::update(float deltaTime)
{
    Tank::update(deltaTime);
    if(!isAllive()) {
        EventType event = EventType::Victory;
        publishEvent(event);
        IEventHandler& botTank = *dynamic_cast<IEventHandler*>(this);
        getEventManager().unsubscribe(botTank);
    }
}

RenderData BotTank::getRenderData() const
{
    RenderData renderData;
    renderData.position = getPosition();
    renderData.size = getSize();
    renderData.type = type;
    renderData.rotation = getRotation();
    return renderData;
}

void BotTank::onEvent(const EventType & event)
{
}
