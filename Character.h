#pragma once

class Spawner;
class Skill;

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
	Skill* _skill;
	bool _isGarbage;

public:
	Character(Vector2 position,
		Vector2 size,
		float speed,
		int currentHealth,
		int maxHealth,
		Texture2D texture);

	void UpdateProtagonist(Spawner* spawner, Rectangle collision);
	void UpdateEnemy(Vector2 target);
	MyTransform* GetTransform();
	Drawer* GetDrawer();
	Movement* GetMovement();
	Health* GetHealth();
	Skill* GetSkill();
	bool IsGarbage();
};
