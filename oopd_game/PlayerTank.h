#pragma once
#include "Tank.h"
#include "RenderData.h"
class PlayerTank : public Tank
{
private:
	std::string sprite = "rectangle";
	std::string color = "green";
	bool movingForward = false;
	bool movingBackward = false;
	bool turningRight = false;
	bool turningLeft = false;
public:
	PlayerTank(EntityManager& entityM, EventManager& eventM, const Vector2& position) : Tank(entityM, eventM, position) {}
	RenderData getRenderData() const override;
	void onEvent(const EventType& event) override;
	void publishEvent(const EventType& event) override;
	void update(float deltaTime) override;
};

