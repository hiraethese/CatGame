#pragma once

#include "raylib.h"
#include "PhysicsBody.h"
#include "Drawer.h"

class Bullet
{
private:
	MyTransform* _transform;
	PhysicsBody* _physicsBody;
	Drawer* _sprite;
	Vector2 _direction;
	bool _isGarbage;

public:
	Bullet(float speed,
		b2World* world,
		Vector2 position,
		Vector2 size,
		Vector2 direction,
		Texture2D texture);

	void Update();
	PhysicsBody* GetPhysicsBody();
	Drawer* GetDrawer();
	bool IsGarbage();
};
