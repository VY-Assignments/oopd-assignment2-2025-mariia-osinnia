#include "EventManager.h"

void EventManager::subscribe(sf::Event event, IEventHandler*& listener)
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

void EventManager::notify(sf::Event event)
{
	if (event_map.find(event) != event_map.end()) {
		std::vector<IEventHandler*> listeners = event_map[event];
		for (auto& l : listeners) {
			l.on
		}
	}
}
