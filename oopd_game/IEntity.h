#pragma once
#include <SFML/Graphics.hpp>
#include "EventType.h"
#include "Vector2.h"

class IEntity {
public:
	virtual void update(float deltaTime) = 0;
	virtual Vector2 getPosition() const = 0;
	virtual float getRotation() const = 0;
	virtual Vector2 getSize() const = 0;
	virtual bool isAllive() = 0; 

	virtual void onCollision(IEntity* entity) = 0;
};
