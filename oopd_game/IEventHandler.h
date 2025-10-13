#pragma once
#include <SFML/Graphics.hpp>
#include "EventType.h"

class IEventHandler {
public:
	virtual void onEvent(const EventType & event) = 0;
	virtual void publishEvent(EventType& event) = 0;
};