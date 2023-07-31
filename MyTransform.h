#pragma once

#include "raylib.h"

class MyTransform
{
private:
	Vector2 _position;
	Vector2 _size;

public:
	MyTransform(Vector2 position,
		Vector2 size);

	void SetPosition(Vector2 newPosition);
	Rectangle GetRectangle();
	Vector2 GetPosition();
	Vector2 GetSize();
};
