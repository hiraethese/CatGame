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
	bool _isStatic;
	bool _isInvunerable;
	bool _isDead;
	Bar* _healthBar;

public:
	Character(Vector2 position, Vector2 size,
		float speed, int currentHealth, int maxHealth);
	void DrawHitbox(Color color);
	void DrawSprite(Texture2D characterSprite);
	void UpdateLocation(Vector2 target);
	void Move(Rectangle recCollision);
	void SetSpeed(float newSpeed);
	void SetInvulnerability(bool isInvunerable);
	void TakeDamage(int damagePoints);
	void HealDamage(int healPoints);
	Rectangle GetHitbox();
	Vector2 GetPosition();
	int GetCurrentHealth();
	int GetMaxHealth();
};
