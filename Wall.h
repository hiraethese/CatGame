#pragma once

#include "raylib.h"
#include "raymath.h"
#include "PhysicsBody.h"
#include "Drawer.h"
#include "Health.h"
#include "Bar.h"

class Wall
{
private:
	MyTransform* _transform;
	Drawer* _sprite;
	PhysicsBody* _physicsBody;

public:
	Wall(b2World* world,
		Vector2 position,
		Vector2 size,
		Color color,
		Texture2D texture);

	void UpdateButton();
	MyTransform* GetTransform();
	Drawer* GetDrawer();
	PhysicsBody* GetPhysicsBody();
};
