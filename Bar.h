#pragma once

#include "raylib.h"

class Bar
{
private:
	Vector2 _position;
	Vector2 _size;
	Color _filledPartColor;
	Color _emptyPartColor;
	int _maxPoints;
	int _currentPoints;
	bool _visibility;
public:
	Bar(Vector2 position, Vector2 size, Color filledPartColor,
		Color emptyPartColor, int maxPoints, int currentPoints);
	void DrawBaseBar();
};

