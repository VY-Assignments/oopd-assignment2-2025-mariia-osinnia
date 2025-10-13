#pragma once
#include <unordered_map>
#include "IEventHandler.h"
#include "EventType.h"
class EventManager
{
private:
	std::unordered_map<EventType, std::vector<IEventHandler*>> event_map;
public:
	EventManager(){}
	void subscribe(const EventType& event, IEventHandler* listener);
	void unsubscribe(EventType& event, IEventHandler* entity);
	void unsubscribe(IEventHandler& entity);
	void notify(const EventType& event);
};

