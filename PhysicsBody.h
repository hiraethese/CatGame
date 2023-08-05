#pragma once

#include "raylib.h"
#include "raymath.h"
#include "globals.h"
#include "Box2D.h"
#include "MyTransform.h"

class PhysicsBody
{
private:
	b2World* _world;
	b2Body* _body;
	MyTransform* _transform;
	float _speed;

public:
	PhysicsBody(b2World* world,
		MyTransform* transform,
		float speed);

	void MoveWithKeyboard();
	void ChaseTarget(Vector2 target);
	void MoveInDirection(Vector2 direction);
	void SetTransform(b2Vec2 newPosition);
	void SetSpeed(float newSpeed);
	MyTransform* GetTransform();
	b2Body* GetBody();
};
