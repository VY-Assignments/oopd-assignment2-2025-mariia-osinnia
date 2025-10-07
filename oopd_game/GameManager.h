#pragma once
#include "EventManager.h"
#include "EntityManager.h"
#include "IEntityFactory.h"
class GameManager
{
private:
	EventManager& eventManager;
	EntityManager& entityManager;
	IEntityFactory& tankFactory;
	IEntityFactory& interactiveObjectFactory;
	bool gameOver = false;
public:
	GameManager(EventManager& eventM, EntityManager& entityM, IEntityFactory& tankF, 
		IEntityFactory& interactiveObjF) : eventManager(eventM), entityManager(entityM), tankFactory(tankF), 
		interactiveObjectFactory(interactiveObjF){
		init();
	}
	void init();
	void update();
};

