#pragma once

#include "Movement.h"
#include "Drawer.h"
#include "Health.h"
#include "Bar.h"

class Character
{
private:
	MyTransform* _transform;
	Drawer* _sprite;
	Movement* _movement;
	Health* _health;
	Bar* _healthBar;
	bool _isGarbage;

public:
	Character(Vector2 position,
		Vector2 size,
		float speed,
		int currentHealth,
		int maxHealth,
		Texture2D texture);

	void UpdateProtagonist(Rectangle collision);
	void UpdateEnemy(Vector2 target);
	MyTransform* GetTransform();
	Drawer* GetDrawer();
	Movement* GetMovement();
	Health* GetHealth();
	bool IsGarbage();
};
