#include "EventManager.h"

void EventManager::subscribe(const EventType& event, IEventHandler* listener)
{
	if (event_map.find(event) != event_map.end()) {
		event_map[event].push_back(listener);
	}
	else {
		std::vector<IEventHandler*> listeners;
		listeners.push_back(listener);
		event_map.insert({event, listeners});
	}
}

void EventManager::notify(const EventType& event)
{
	auto it = event_map.find(event);
	if (it != event_map.end()) {
		for (auto& listener : it->second) {
			listener->onEvent(event);
		}
	}
}
