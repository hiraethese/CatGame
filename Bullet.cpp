#include "Bullet.h"

Bullet::Bullet(Vector2 position, Vector2 velocity, Color color,
	float radius, double lifetime, int damage)
{
	_position = position;
	_velocity = velocity;
	_color = color;
	_radius = radius;
	_lifetime = lifetime;
	_damage = damage;
	_spawntime = GetTime();
	_isActive = true;
}

void Bullet::DrawBulletHitbox()
{
	if (_isActive) {
		DrawCircleV(_position, 5, _color);
	}
}

void Bullet::DrawBulletSprite(Texture2D bulletSprite)
{
	if (_isActive) {
		DrawTexture(bulletSprite, static_cast<int>(_position.x),
			static_cast<int>(_position.y), WHITE);
	}
}

void Bullet::UpdateBullet(double currentTime)
{
	if (_isActive)
	{
		_position.x += _velocity.x;
		_position.y += _velocity.y;

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

Vector2 Bullet::GetBulletCenter()
{
	return _position;
}

float Bullet::GetBulletRadius()
{
	return _radius;
}

bool Bullet::BulletIsActive()
{
	return _isActive;
}

void Bullet::DeleteBullet()
{
	_isActive = false;
}
