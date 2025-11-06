#pragma once
#include "EventType.h"

class IEventHandler {
public:
	virtual void onEvent(const EventType & event) = 0;
	virtual void publishEvent(const EventType& event) = 0;
	virtual	~IEventHandler() = default;
};