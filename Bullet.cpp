#include "Bullet.h"

Bullet::Bullet(Vector2 position, Vector2 velocity,
	float radius, double lifetime, int damage)
{
	_position = position;
	_velocity = velocity;
	_radius = radius;
	_lifetime = lifetime;
	_damage = damage;
	_spawntime = GetTime();
	_isActive = true;
}

void Bullet::DrawHitbox()
{
	if (_isActive) {
		DrawCircleV(_position, 5, RED);
	}
}

void Bullet::DrawSprite(Texture2D bulletSprite)
{
	if (_isActive) {
		DrawTexture(bulletSprite, static_cast<int>(_position.x),
			static_cast<int>(_position.y), WHITE);
	}
}

void Bullet::UpdateLocation(double currentTime)
{
	if (_isActive)
	{
		_position.x += _velocity.x * GetFrameTime();
		_position.y += _velocity.y * GetFrameTime();

		if (_position.x > GetScreenWidth() || _position.x < 0 ||
			_position.y > GetScreenHeight() || _position.y < 0)
		{
			_isActive = false;
		}

		if (currentTime - _spawntime >= _lifetime)
		{
			_isActive = false;
		}
	}
}

Vector2 Bullet::GetCenter()
{
	return _position;
}

float Bullet::GetRadius()
{
	return _radius;
}

bool Bullet::IsActive()
{
	return _isActive;
}

void Bullet::Delete()
{
	_isActive = false;
}
