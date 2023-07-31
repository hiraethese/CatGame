#pragma once

#include "raylib.h"
#include "MyTransform.h"
#include "Drawer.h"
#include "Movement.h"

class Bullet
{
private:
	MyTransform* _transform;
	Drawer* _sprite;
	Movement* _movement;
	Vector2 _direction;

public:
	Bullet(Vector2 position,
		Vector2 target,
		Vector2 size,
		float speed,
		Texture2D texture);

	void Update();
	MyTransform* GetTransform();
	Drawer* GetDrawer();
	Movement* GetMovement();
};
