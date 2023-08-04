#pragma once

#include "raylib.h"
#include "raymath.h"
#include "globals.h"
#include "Box2D.h"
#include "MyTransform.h"

class PhysicsBody
{
private:
	float _speed;
	b2World* _world;
	MyTransform* _transform;
	b2Body* _body;

public:
	PhysicsBody(float speed,
		b2World* world,
		MyTransform* transform);

	void SetSpeed(float newSpeed);
	void MoveWithKeyboard();
	void ChaseTarget(Vector2 target);
	void MoveInDirection(Vector2 direction);
	bool CheckCollision(const b2Vec2& velocity);
	MyTransform* GetTransform();
};
