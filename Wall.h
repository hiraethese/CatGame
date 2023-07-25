#pragma once

#include <iostream>
#include "raylib.h"

class Wall
{
private:
	Vector2 _position;
	Vector2 _size;
	Color _color;
	std::string _label;
	int _currentHealth;
	int _maxHealth;
	bool _visibility;
	bool _isDead;

public:
	Wall(Vector2 position, Vector2 size, Color color,
		const std::string &label, int currentHealth, int maxHealth);
	void DrawWallHitbox();
	void ChangeWallLocation(Vector2 newPosition, Vector2 newSize);
	void ChangeWallColor(Color newColor);
	void ChangeWallLabel(const std::string& newLabel);
	Rectangle GetWallHitbox();
};
