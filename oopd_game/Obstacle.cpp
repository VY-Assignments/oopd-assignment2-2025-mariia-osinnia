#include "Obstacle.h"

RenderData Obstacle::getRenderData() const
{
    RenderData renderData;
    renderData.position = position;
    renderData.size = size;
    renderData.shape = shape;
    renderData.color = color;
    return renderData;
}

void Obstacle::onCollision(ICollidable* other)
{
}

