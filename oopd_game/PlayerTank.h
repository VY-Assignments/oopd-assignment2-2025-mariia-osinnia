#pragma once
#include "Tank.h"
#include "RenderData.h"
class PlayerTank : public Tank
{
private:
	int health = 100;
	std::string sprite = "rectangle";
	std::string color = "green";
	bool movingForward = false;
	bool movingBackward = false;
	bool turningRight = false;
	bool turningLeft = false;
public:
	PlayerTank(Vector2& position, int h = 100) : Tank(position), health(h) {}
	RenderData getRenderData() const override;
	void onEvent(const EventType& event) override;
	void publishEvent(EventType& event) override;
	void update(float deltaTime) override;
};

