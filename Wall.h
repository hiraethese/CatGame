#pragma once

#include <iostream>
#include "raylib.h"
#include "BarDisplay.h"

class Wall
{
private:
	Vector2 _position;
	Vector2 _size;
	Color _color;
	std::string _label;
	int _currentHealth;
	int _maxHealth;
	bool _isVisible;
	bool _isInvunerable;
	bool _isDestroyed;

public:
	Wall(Vector2 position,
		Vector2 size,
		Color color,
		const std::string &label,
		int currentHealth,
		int maxHealth);

	void DrawHitbox();
	void ChangeLocation(Vector2 newPosition, Vector2 newSize);
	void ChangeColor(Color newColor);
	void ChangeLabel(const std::string& newLabel);
	void SetInvulnerability(bool isInvunerable);
	void TakeDamage(int damagePoints);
	void HealDamage(int healPoints);
	Rectangle GetHitbox();
	int GetCurrentHealth();
	int GetMaxHealth();
};
