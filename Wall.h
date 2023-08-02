#pragma once

#include "raylib.h"
#include "raymath.h"
#include "MyTransform.h"
#include "Drawer.h"
#include "Health.h"
#include "Bar.h"

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
