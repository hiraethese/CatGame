#pragma once

#include <iostream>
#include "raylib.h"
#include "Movement.h"
#include "SpriteDrawer.h"
#include "Health.h"
#include "BarDisplay.h"

class Character
{
private:
	MyTransform* _transform;
	SpriteDrawer* _drawer;
	Movement* _movement;
	Health* _health;
	BarDisplay* _healthBar;

public:
	Character(Vector2 position,
		Vector2 size,
		float speed,
		int currentHealth,
		int maxHealth,
		Texture2D texture);

	void Update(Rectangle collision);
	MyTransform* GetTransform();
	SpriteDrawer* GetDrawer();
	Movement* GetMovement();
	Health* GetHealth();
};
