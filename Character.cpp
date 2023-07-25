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
	_visibility = true;
	_isDead = false;
}

void Character::DrawCharacterHitbox()
{
	DrawRectangleRec(GetCharacterHitbox(), WHITE);
}

void Character::DrawCharacterSprite(Texture2D characterSprite)
{
	DrawTexture(characterSprite, static_cast<int>(_position.x),
		static_cast<int>(_position.y), WHITE);
}

void Character::MoveCharacter(Rectangle wall)
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

	_position.x += movement.x * _speed;
	_position.y += movement.y * _speed;

	if ( _position.x < 0 ) _position.x = 0;
	if ( _position.x + _size.x > GetScreenWidth() )
		 _position.x = GetScreenWidth() - _size.x;
	if ( _position.y < 0 ) _position.y = 0;
	if ( _position.y + _size.y > GetScreenHeight() )
		 _position.y = GetScreenHeight() - _size.y;

	if (CheckCollisionRecs(GetCharacterHitbox(), wall))
	{
		if (movement.x > 0 && _position.x < wall.x)
		{
			_position.x = wall.x - _size.x;
		}
		else if (movement.x < 0 && _position.x + _size.x > wall.x + wall.width)
		{
			_position.x = wall.x + wall.width;
		}

		if (movement.y > 0 && _position.y < wall.y)
		{
			_position.y = wall.y - _size.y;
		}
		else if (movement.y < 0 && _position.y + _size.y > wall.y + wall.height)
		{
			_position.y = wall.y + wall.height;
		}
	}
}

void Character::TakeDamage(int damagePoints)
{
	_currentHealth -= damagePoints;

	if (_currentHealth <= 0)
	{
		_currentHealth = 0;
		_isDead = true;
	}
}

void Character::HealDamage(int healPoints)
{
	_currentHealth += healPoints;

	if (_currentHealth > _maxHealth)
	{
		_currentHealth = _maxHealth;
	}
}

void Character::SetCharacterSpeed(float newSpeed)
{
	_speed = newSpeed;
}

Rectangle Character::GetCharacterHitbox()
{
	Rectangle character = { _position.x, _position.y, _size.x, _size.y };
	return character;
}
