#pragma once
#include "IEntity.h"
#include "InteractiveObject.h"
#include "Vector2.h"

class Mine : public InteractiveObject
{
private:
	int damage = 100;
	std::string color = "pink";
	std::string sprite = "rectangle";
public:
	Mine(Vector2& p, int d = 10) : InteractiveObject(p), damage(d){}


	void onEvent(const EventType& event) override;
	void publishEvent(EventType& event) override;
	void interact(Tank* tank) override;
	RenderData getRenderData() const override;
};

