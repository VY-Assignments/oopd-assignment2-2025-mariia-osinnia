#pragma once
#include "IEventHandler.h"
class EventManager
{
private:
	std::map<sf::Event, std::vector<IEventHandler*>> event_map;
public:
	EventManager(){}
	void subscribe(sf::Event event, IEventHandler*& listener);
	void unsubscribe(sf::Event, IEventHandler& entity);
	void unsubscribe(IEventHandler& entity);
	void notify(sf::Event event);
};

