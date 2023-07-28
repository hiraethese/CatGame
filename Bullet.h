#pragma once

#include "raylib.h"

class Bullet
{
private:
	Vector2 _position;
	Vector2 _velocity;
	float _radius;
	double _lifetime;
	int _damage;
	double _spawntime;
	bool _isActive;

public:
	Bullet(Vector2 position, Vector2 velocity,
		float radius, double lifetime, int damage);
	void DrawHitbox();
	void DrawSprite(Texture2D bulletSprite);
	void UpdateLocation(double currentTime);
	Vector2 GetCenter();
	float GetRadius();
	bool IsActive();
	void Delete();
};
