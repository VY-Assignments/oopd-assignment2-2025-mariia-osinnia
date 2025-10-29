#include "Tank.h"
#include "Projectile.h"
#include "EntityManager.h" 
#include "Obstacle.h"
#include <iostream>

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
		float tankHalfLength = size.x / 2;
		float projectileOffset = 5.0f;
		Vector2 projectileSpawn = position + direction * (tankHalfLength + projectileOffset);

		entityManager.addEntity(std::make_unique<Projectile>(projectileSpawn, direction));
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

void Tank::onCollision(ICollidable* other)
{
	if (Obstacle* obstacle = dynamic_cast<Obstacle*>(other)) {
		position -= direction * speed * 0.01f;
	}
}



