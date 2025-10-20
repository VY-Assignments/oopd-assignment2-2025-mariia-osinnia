#include "InteractiveObject.h"
#include "Tank.h"

void InteractiveObject::update(float deltaTime)
{

}

void InteractiveObject::onCollision(IEntity* entity)
{
	if (Tank* tank = dynamic_cast<Tank*>(entity)) {
		interact(tank);
	}
}





