#pragma once

#include <iostream>
#include "raylib.h"
#include "Bar.h"

class Character
{
private:
	Vector2 _position;
	Vector2 _size;
	float _speed;
	int _currentHealth;
	int _maxHealth;
	bool _isVisible;
	bool _isInvunerable;
	bool _isDead;

public:
	Character(Vector2 position, Vector2 size,
		float speed, int currentHealth, int maxHealth);
	void DrawHitbox();
	void DrawSprite(Texture2D characterSprite);
	void Move(Rectangle recCollision);
	void SetSpeed(float newSpeed);
	void SetInvulnerability(bool isInvunerable);
	void TakeDamage(int damagePoints, Bar* healthBar);
	void HealDamage(int healPoints, Bar* healthBar);
	Rectangle GetHitbox();
	int GetCurrentHealth();
	int GetMaxHealth();
};
