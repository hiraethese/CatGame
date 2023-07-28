#include "Character.h"
#include "Bar.h"
#include "raymath.h"
#include <cmath>

Character::Character(Vector2 position, Vector2 size,
	float speed, int currentHealth, int maxHealth)
{
	_position = position;
	_size = size;
	_speed = speed;
	_currentHealth = currentHealth;
	_maxHealth = maxHealth;
	_isVisible = true;
	_isStatic = false;
	_isInvunerable = false;
	_isDead = false;
	_healthBar = new Bar( { 40.0f, 5.0f }, GREEN, GRAY, 100, 100 );
}

void Character::DrawHitbox(Color color)
{
	if (!_isDead)
	{
		DrawRectangleRec(GetHitbox(), color);
	}
}

void Character::DrawSprite(Texture2D characterSprite)
{
	if (!_isDead)
	{
		DrawTexture(characterSprite, static_cast<int>(_position.x),
			static_cast<int>(_position.y), WHITE);

		_healthBar->DrawBase(_position);
	}
}

void Character::UpdateLocation(Vector2 target)
{
	if (!_isDead)
	{
		Vector2 direction = Vector2Subtract(target, _position);
		direction = Vector2Normalize(direction);
		Vector2 velocity = { direction.x * _speed, direction.y * _speed };

		if (!_isStatic)
		{
			_position.x += velocity.x * GetFrameTime();
			_position.y += velocity.y * GetFrameTime();
		}
	}
}

void Character::Move(Rectangle recCollision)
{
	if (!_isDead)
	{
		Vector2 direction = { 0.0f, 0.0f };

		if (IsKeyDown(KEY_W)) {
			direction.y -= 1.0f;
		}
		if (IsKeyDown(KEY_S)) {
			direction.y += 1.0f;
		}
		if (IsKeyDown(KEY_A)) {
			direction.x -= 1.0f;
		}
		if (IsKeyDown(KEY_D)) {
			direction.x += 1.0f;
		}

		direction = Vector2Normalize(direction);

		_position.x += direction.x * _speed * GetFrameTime();
		_position.y += direction.y * _speed * GetFrameTime();

		if (_position.x < 0) _position.x = 0;
		if (_position.x + _size.x > GetScreenWidth())
			_position.x = GetScreenWidth() - _size.x;
		if (_position.y < 0) _position.y = 0;
		if (_position.y + _size.y > GetScreenHeight())
			_position.y = GetScreenHeight() - _size.y;

		if (CheckCollisionRecs(GetHitbox(), recCollision))
		{
			if (direction.x > 0 && _position.x < recCollision.x)
			{
				_position.x = recCollision.x - _size.x;
			}
			else if (direction.x < 0 && _position.x + _size.x > recCollision.x + recCollision.width)
			{
				_position.x = recCollision.x + recCollision.width;
			}

			if (direction.y > 0 && _position.y < recCollision.y)
			{
				_position.y = recCollision.y - _size.y;
			}
			else if (direction.y < 0 && _position.y + _size.y > recCollision.y + recCollision.height)
			{
				_position.y = recCollision.y + recCollision.height;
			}
		}
	}
}

void Character::SetSpeed(float newSpeed)
{
	_speed = newSpeed;
}

void Character::SetInvulnerability(bool isInvunerable)
{
	_isInvunerable = isInvunerable;
}

void Character::TakeDamage(int damagePoints)
{
	if (!_isInvunerable)
	{
		_currentHealth -= damagePoints;

		if (_currentHealth <= 0)
		{
			_currentHealth = 0;
			_isDead = true;
		}
	}
}

void Character::HealDamage(int healPoints)
{
	_currentHealth += healPoints;

	if (_currentHealth >= _maxHealth)
	{
		_currentHealth = _maxHealth;
	}
}

Rectangle Character::GetHitbox()
{
	return { _position.x, _position.y, _size.x, _size.y };
}

Vector2 Character::GetPosition()
{
	return _position;
}

int Character::GetCurrentHealth()
{
	return _currentHealth;
}

int Character::GetMaxHealth()
{
	return _maxHealth;
}
