#include "CollisionManager.h"
#include "Tank.h"
#include "Projectile.h"
#include "InteractiveObject.h"
void CollisionManager::checkCollision()
{
    std::vector<std::unique_ptr<IEntity>>& entities = entityManager.getEntities();

    for (size_t i = 0; i < entities.size(); ++i) {
        for (size_t j = i + 1; j < entities.size(); ++j) {
            IEntity* a = entities[i].get();
            IEntity* b = entities[j].get();

            if (checkAABB(a->getPosition(), a->getSize(),
                b->getPosition(), b->getSize())) {
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


