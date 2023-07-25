#include "Character.h"
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
	_isInvunerable = false;
	_isDead = false;
}

void Character::DrawHitbox()
{
	DrawRectangleRec(GetHitbox(), WHITE);
}

void Character::DrawSprite(Texture2D characterSprite)
{
	DrawTexture(characterSprite, static_cast<int>(_position.x),
		static_cast<int>(_position.y), WHITE);
}

void Character::Move(Rectangle recCollision)
{
	Vector2 movement = { 0.0f, 0.0f };

	if (IsKeyDown(KEY_W)) {
		movement.y -= 1.0f;
	}
	if (IsKeyDown(KEY_S)) {
		movement.y += 1.0f;
	}
	if (IsKeyDown(KEY_A)) {
		movement.x -= 1.0f;
	}
	if (IsKeyDown(KEY_D)) {
		movement.x += 1.0f;
	}

	movement = Vector2Normalize(movement);

	_position.x += movement.x * _speed * GetFrameTime();
	_position.y += movement.y * _speed * GetFrameTime();

	if ( _position.x < 0 ) _position.x = 0;
	if ( _position.x + _size.x > GetScreenWidth() )
		 _position.x = GetScreenWidth() - _size.x;
	if ( _position.y < 0 ) _position.y = 0;
	if ( _position.y + _size.y > GetScreenHeight() )
		 _position.y = GetScreenHeight() - _size.y;

	if (CheckCollisionRecs(GetHitbox(), recCollision))
	{
		if (movement.x > 0 && _position.x < recCollision.x)
		{
			_position.x = recCollision.x - _size.x;
		}
		else if (movement.x < 0 && _position.x + _size.x > recCollision.x + recCollision.width)
		{
			_position.x = recCollision.x + recCollision.width;
		}

		if (movement.y > 0 && _position.y < recCollision.y)
		{
			_position.y = recCollision.y - _size.y;
		}
		else if (movement.y < 0 && _position.y + _size.y > recCollision.y + recCollision.height)
		{
			_position.y = recCollision.y + recCollision.height;
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

void Character::TakeDamage(int damagePoints, Bar* healthBar)
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

void Character::HealDamage(int healPoints, Bar* healthBar)
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

int Character::GetCurrentHealth()
{
	return _currentHealth;
}

int Character::GetMaxHealth()
{
	return _maxHealth;
}
