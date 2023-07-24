#pragma once

#include "raylib.h"

class Character
{
private:
	Vector2 _position;
	Vector2 _size;
	float _speed;
	int _currentHealth;
	int _maxHealth;

public:
	Character(Vector2 position, Vector2 size,
		float speed, int currentHealth, int maxHealth);
	void DrawCharacterHitbox();
	void DrawCharacterSprite(Texture2D characterSprite);
	void MoveCharacter(Rectangle wall);
	void TakeDamage(int damagePoints);
	void SetNewMaxHealth(int newMaxHealth);
	void SetCharacterSpeed(float newSpeed);
	Rectangle GetCharacterHitbox();
};
