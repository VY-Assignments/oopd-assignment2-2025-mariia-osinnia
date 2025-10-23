#include "GameManager.h"
#include "IEntityFactory.h"
#include "EventType.h"
#include "Tank.h"
#include "Vector2.h"
#include "BotTank.h"
#include "Mine.h"
#include "HealthPack.h"
#include <random>

void GameManager::init() {
	Vector2 playerPosition = { 320, 360 };
	std::string type = "player";
	std::unique_ptr<IEntity> playerTank = tankFactory.create(type, playerPosition);
	PlayerTank* playerPtr = dynamic_cast<PlayerTank*>(playerTank.get());
	eventManager.subscribe(EventType::MovingForward, dynamic_cast<IEventHandler*>(playerTank.get()));
	eventManager.subscribe(EventType::MovingBackward, dynamic_cast<IEventHandler*>(playerTank.get()));
	eventManager.subscribe(EventType::TurnLeft, dynamic_cast<IEventHandler*>(playerTank.get()));
	eventManager.subscribe(EventType::TurnRight, dynamic_cast<IEventHandler*>(playerTank.get()));
	eventManager.subscribe(EventType::Stop, dynamic_cast<IEventHandler*>(playerTank.get()));
	eventManager.subscribe(EventType::Shoot, dynamic_cast<IEventHandler*>(playerTank.get()));
	entityManager.addEntity(std::move(playerTank));

	Vector2 botPosition = { 960, 360 };
	std::string type1 = "bot";
	std::unique_ptr<IEntity> botTank = tankFactory.create(type1, botPosition);
	BotTank* botPtr = dynamic_cast<BotTank*>(botTank.get());
	botPtr->setTarget(playerPtr);
	entityManager.addEntity(std::move(botTank));

	eventManager.subscribe(EventType::GameOver, dynamic_cast<IEventHandler*>(this));
    eventManager.subscribe(EventType::Victory, dynamic_cast<IEventHandler*>(this));
}
void GameManager::update(float deltaTime)
{
    if (gameState != GameState::Running) {
        IEventHandler& gameManager = *dynamic_cast<IEventHandler*>(this);
        return;
    }

    timeSinceLastMine += deltaTime;
    timeSinceLastHealthPack += deltaTime;

    if (timeSinceLastMine >= mineSpawnInterval) {
        Vector2 pos = getRandomPosition();
        entityManager.addEntity(std::make_unique<Mine>(pos));
        timeSinceLastMine = 0.0f;
    }

    if (timeSinceLastHealthPack >= healthPackSpawnInterval) {
        Vector2 pos = getRandomPosition();
        entityManager.addEntity(std::make_unique<HealthPack>(pos));
        timeSinceLastHealthPack = 0.0f;
    }
}

void GameManager::reset()
{
    eventManager.unsubscribeAll();
    entityManager.clear();
    init();
    gameState = GameState::Running;
    timeSinceLastHealthPack = 0.0f;
    timeSinceLastMine = 0.0f;
}

Vector2 GameManager::getRandomPosition()
{
    const float MAP_WIDTH = 1280.0f;
    const float MAP_HEIGHT = 720.0f;
    const float MARGIN = 50.0f;
    const float UI_HEIGHT = 100.0f;
    std::uniform_real_distribution<float> distX(MARGIN, MAP_WIDTH - MARGIN);
    std::uniform_real_distribution<float> distY(UI_HEIGHT, MAP_HEIGHT - MARGIN);
    return Vector2{ distX(rng), distY(rng) };
}

void GameManager::onEvent(const EventType& event)
{
    if(event == EventType::GameOver) {
        gameState = GameState::GameOver;
    }
    else if (event == EventType::Victory) {
        gameState = GameState::Victory;
    }
}

void GameManager::publishEvent(EventType& event)
{
}
