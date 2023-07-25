#pragma once

#include "raylib.h"

class Character
{
private:
	Vector2 _position;
	Vector2 _size;
	bool _visibility;
	bool _isDead;

public:
	Character(Vector2 position, Vector2 size,
		float speed, int currentHealth, int maxHealth);
	void DrawCharacterHitbox();
	void DrawCharacterSprite(Texture2D characterSprite);
	void MoveCharacter(Rectangle wall);
	void TakeDamage(int damagePoints);
	void HealDamage(int healPoints);
	void SetCharacterSpeed(float newSpeed);
	Rectangle GetCharacterHitbox();

	int _maxHealth;
	int _currentHealth;
	float _speed;
};
