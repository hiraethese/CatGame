#pragma once

#include <vector>
#include "Character.h"
#include "Bullet.h"

class Spawner
{
private:
	std::vector<Character*> _enemies;
	std::vector<Bullet*> _bullets;

public:
	Spawner();
	void AddEnemy(Character* enemy);
	void AddBullet(Bullet* bullet);
	void UpdateEnemies(Vector2 target);
	void UpdateBullets();
	void SpawnSimpleEnemy(Vector2 startPos, Texture2D sprite);
	void SpawnBulletWithTarget(Vector2 startPos, Vector2 targetPos, Texture2D sprite);
};
