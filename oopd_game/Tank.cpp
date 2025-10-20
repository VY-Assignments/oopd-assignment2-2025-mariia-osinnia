#include "Tank.h"
#include "Projectile.h"
#include "EntityManager.h" 

void Tank::update(float deltaTime)
{
	timeSinceLastShot += deltaTime;
	if (health <= 0) {
		isAlive = false;
	}
}

void Tank::shoot()
{
	if (timeSinceLastShot >= fireCooldown) {
		entityManager.addEntity(std::make_unique<Projectile>(position, direction));
		timeSinceLastShot = 0.0f;
	}
}

void Tank::takeDamage(int damage)
{
	health -= damage;
}

void Tank::heal(int healBonus)
{
	health += healBonus;
}

void Tank::onCollision(IEntity* entity)
{
}



