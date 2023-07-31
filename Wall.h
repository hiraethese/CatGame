#pragma once

#include <iostream>
#include "raylib.h"
#include "MyTransform.h"
#include "Bar.h"
#include "Health.h"

class Wall
{
private:
	MyTransform* _transform;
	Drawer* _sprite;
	Health* _health;
	Bar* _healthBar;

public:
	Wall(Vector2 position,
		Vector2 size,
		Color color,
		int currentHealth,
		int maxHealth,
		Texture2D texture);

	void UpdateButton();
	MyTransform* GetTransform();
	Drawer* GetDrawer();
	Health* GetHealth();
};
