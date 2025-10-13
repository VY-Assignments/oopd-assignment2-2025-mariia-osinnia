#pragma once
enum class EventType {
	MovingForward,
	MovingBackward,
	TurnRight,
	TurnLeft,
	Stop,
	Collision,
	Shoot,
	GameOver,
	None
};