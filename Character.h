#pragma once

class Spawner;
class Skill;

#include "PhysicsBody.h"
#include "Drawer.h"
#include "Health.h"
#include "Bar.h"

class Character
{
private:
	MyTransform* _transform;
	PhysicsBody* _physicsBody;
	Drawer* _sprite;
	Health* _health;
	Bar* _healthBar;
	Skill* _skill;
	bool _isGarbage;

public:
	Character(b2World* world,
		Vector2 position,
		Vector2 size,
		float speed,
		int currentHealth,
		int maxHealth,
		Texture2D texture);

	void UpdateProtagonist(Spawner* spawner);
	void UpdateEnemy(Vector2 target);
	MyTransform* GetTransform();
	Drawer* GetDrawer();
	PhysicsBody* GetPhysicsBody();
	Health* GetHealth();
	Skill* GetSkill();
	bool IsGarbage();
};
