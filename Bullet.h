#pragma once

#include "Movement.h"
#include "Drawer.h"

class Bullet
{
private:
	MyTransform* _transform;
	Drawer* _sprite;
	Movement* _movement;
	Vector2 _direction;
	bool _isGarbage;

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
	bool IsGarbage();
};
