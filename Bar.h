#pragma once

#include "raylib.h"

class Bar
{
private:
	Vector2 _size;
	Color _filledPartColor;
	Color _emptyPartColor;
	int _maxPoints;
	int _currentPoints;
	bool _isVisible;

public:
	Bar(Vector2 size, Color filledPartColor,
		Color emptyPartColor, int maxPoints, int currentPoints);
	void DrawBase(Vector2 position);
	void SetPoints(int newMaxPoints, int newCurrentPoints);
};

