#include "CollisionManager.h"
#include "Tank.h"
#include "Projectile.h"
#include "InteractiveObject.h"
#include <cmath>

void CollisionManager::checkCollision()
{
    std::vector<std::unique_ptr<IEntity>>& entities = entityManager.getEntities();
    float PI = 3.1415926f;

    for (size_t i = 0; i < entities.size(); ++i) {
        for (size_t j = i + 1; j < entities.size(); ++j) {
            IEntity* a = entities[i].get();
            IEntity* b = entities[j].get();

            float radA = a->getRotation() * PI / 180.0f;
            float radB = b->getRotation() * PI / 180.0f;

            if (checkOBB(a->getPosition(), a->getSize(), radA,
                b->getPosition(), b->getSize(), radB)) {
                a->onCollision(b);
                b->onCollision(a);
            }
        }
    }
}

bool CollisionManager::checkAABB(const Vector2& position1, const Vector2& size1, const Vector2& position2, const Vector2& size2)
{
	return (
		std::abs(position1.x - position2.x) * 2 < (size1.x + size2.x) &&
		std::abs(position1.y - position2.y) * 2 < (size1.y + size2.y)
		);
}

bool CollisionManager::checkOBB(const Vector2& position1, const Vector2& size1, const float rotation1, 
    const Vector2& position2, const Vector2& size2, const float rotation2)
{
    Vector2 axesA[2] = { { std::cos(rotation1), std::sin(rotation1) }, { -std::sin(rotation1), std::cos(rotation1) } };
    Vector2 axesB[2] = { { std::cos(rotation2), std::sin(rotation2) }, { -std::sin(rotation2), std::cos(rotation2) } };
    Vector2 axes[4] = { axesA[0], axesA[1], axesB[0], axesB[1] };

    Vector2 T = { position2.x - position1.x, position2.y - position1.y };

    int numberOfAxes = 4;
    for (int i = 0; i < numberOfAxes; ++i)
    {
        Vector2 axis = axes[i];

        float rA = std::abs((size1.x / 2) * (axis.x * axesA[0].x + axis.y * axesA[0].y))
            + std::abs((size1.y / 2) * (axis.x * axesA[1].x + axis.y * axesA[1].y));

        float rB = std::abs((size2.x / 2) * (axis.x * axesB[0].x + axis.y * axesB[0].y))
            + std::abs((size2.y / 2) * (axis.x * axesB[1].x + axis.y * axesB[1].y));

        float distance = std::abs(T.x * axis.x + T.y * axis.y);

        if (distance > rA + rB)
            return false;
    }

    return true;
}


