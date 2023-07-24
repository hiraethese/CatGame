#pragma once

#include "raylib.h"

class Bullet
{
private:
	Vector2 _position;
	Vector2 _velocity;
	Color _color;
	float _radius;
	double _lifetime;
	int _damage;
	double _spawntime;
	bool _isActive;

public:
	Bullet(Vector2 position, Vector2 velocity, Color color,
		float radius, double lifetime, int damage);
	void DrawBulletHitbox();
	void DrawBulletSprite(Texture2D bulletSprite);
	void UpdateBullet(double currentTime);
	Vector2 GetBulletCenter();
	float GetBulletRadius();
	bool BulletIsActive();
	void DeleteBullet();
};
