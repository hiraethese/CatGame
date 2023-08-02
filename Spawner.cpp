#include "Spawner.h"

Spawner::Spawner() {}

void Spawner::AddEnemy(Character* enemy)
{
	_enemies.push_back(enemy);
}

void Spawner::AddBullet(Bullet* bullet)
{
	_bullets.push_back(bullet);
}

void Spawner::UpdateEnemies(Vector2 target)
{
	for ( size_t i = 0; i < _enemies.size(); i++ ) {
		_enemies[i]->UpdateEnemy(target);
	}
}

void Spawner::UpdateBullets()
{
	for ( size_t i = 0; i < _bullets.size(); i++ ) {
		_bullets[i]->Update();

		if ( _bullets[i]->IsGarbage() ) {
			delete _bullets[i];
			_bullets.erase(_bullets.begin() + i);
			i--;
		}
	}
}

void Spawner::SpawnSimpleEnemy(Vector2 startPos, Texture2D sprite)
{
	Vector2 size = { 100.0f, 100.0f };
	float speed = 200.0f;
	int currentHealth = 100;
	int maxHealth = 100;

	Character* enemy = new Character(startPos, size, speed, currentHealth, maxHealth, sprite);

	AddEnemy(enemy);
}

void Spawner::SpawnBulletWithTarget(Vector2 startPos, Vector2 targetPos, Texture2D sprite)
{
	Vector2 size = { 100.0f, 100.0f };
	float speed = 500.0f;

	Bullet* bullet = new Bullet(startPos, targetPos, size, speed, sprite);

	AddBullet(bullet);
}
