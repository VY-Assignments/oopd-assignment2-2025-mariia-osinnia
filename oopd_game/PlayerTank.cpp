#include "PlayerTank.h"

RenderData PlayerTank::getRenderData() const
{
    RenderData renderData;
    renderData.position = getPosition();
    renderData.size = getSize();
    renderData.color = color;
    renderData.shape = sprite;
    renderData.rotation = getRotation();
    return renderData;
}

void PlayerTank::onEvent(const EventType & event)
{
    float rotation = getRotation();
    float rotationSpeed = getRotationSpeed();
    switch (event) {
    case EventType::MovingForward: 
        movingForward = true; 
        movingBackward = false;
        break;
    case EventType::MovingBackward: 
        movingForward = false;
        movingBackward = true;
        break;
    case EventType::TurnRight:
        turningRight = true;
        turningLeft = false;
        break;
    case EventType::TurnLeft:
        turningRight = false;
        turningLeft = true;
        break;
    case EventType::Stop:
        movingForward = false;
        movingBackward = false;
        turningRight = false;
        turningLeft = false;
        break;
    case EventType::Shoot:
        shoot();
        break;
    }
}

void PlayerTank::publishEvent(EventType& event)
{

}

void PlayerTank::update(float deltaTime)
{
    Tank::update(deltaTime);
    const float PI = 3.1415926f;

    float rotation = getRotation();
    float rotationSpeed = getRotationSpeed();

    if (turningLeft) rotation -= rotationSpeed * deltaTime;
    if (turningRight) rotation += rotationSpeed * deltaTime;
    setRotation(rotation);

    float radRotation = rotation * PI / 180;

    float speed = getSpeed();
    Vector2 position = getPosition();

    Vector2 direction = { std::cos(radRotation), std::sin(radRotation) };
    setDirection(direction);
    if (movingForward)  position += direction * speed * deltaTime;
    if (movingBackward) position -= direction * speed * deltaTime;

    setPosition(position);
}

