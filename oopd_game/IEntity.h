#pragma once
#include <SFML/Graphics.hpp>
#include "EventType.h"
class IEntity {
public:
	virtual void update(float deltaTime) = 0;
};
