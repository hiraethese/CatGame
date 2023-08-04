#pragma once

#include "raylib.h"
#include "Box2D.h"

class MyTransform
{
private:
	b2World* _world;
	b2Body* _body;
	Vector2 _position;
	Vector2 _size;

public:
	MyTransform(b2World* world,
		Vector2 position,
		Vector2 size);

	void SetPosition(Vector2 newPosition);
	b2Body* GetBody();
	Rectangle GetRectangle();
	Vector2 GetPosition();
	Vector2 GetSize();
};
