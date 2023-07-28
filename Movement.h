#pragma once

#include "MyTransform.h"

class Movement
{
private:
	float _speed;
	MyTransform* _transform;

public:
	Movement(float speed, MyTransform* transform);
	void UpdateLocation(Vector2 target);
	void Move(Rectangle recCollision);
	void SetSpeed(float newSpeed);
};
