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

void BotTank::findPlayer()
{
    EntityManager& entityManager = getEntityManager();
    std::vector<std::unique_ptr<IEntity>>& entities = entityManager.getEntities();
    for (auto& entity : entities) {
        if (PlayerTank* playerTank = dynamic_cast<PlayerTank*>(entity.get())) {
            targetPlayer = playerTank;
            break;
        }
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
