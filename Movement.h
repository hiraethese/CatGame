#pragma once

#include "raylib.h"
#include "raymath.h"
#include "MyTransform.h"

class Movement
{
private:
	float _speed;
	MyTransform* _transform;

public:
	Movement(float speed,
		MyTransform* transform);

	void MoveWithKeyboard(Rectangle collision);
	void MoveInDirection(Vector2 direction);
	void ChaseTarget(Vector2 target);
	void SetSpeed(float newSpeed);
};
