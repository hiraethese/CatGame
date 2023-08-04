#pragma once

#include <vector>
#include "Character.h"
#include "Bullet.h"

class Spawner
{
private:
	b2World* _world;
	std::vector<Character*> _enemies;
	std::vector<Bullet*> _bullets;

public:
	Spawner(b2World* world);

	void AddEnemy(Character* enemy);
	void AddBullet(Bullet* bullet);

	void UpdateEnemies(Vector2 target);
	void UpdateBullets();

	void SpawnSimpleEnemy(Vector2 startPos, Texture2D sprite);
	void SpawnBulletWithDirection(Vector2 startPos, Vector2 direction, Texture2D sprite);
};
