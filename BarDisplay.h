#pragma once

#include "raylib.h"
#include "MyTransform.h"
#include "SpriteDrawer.h"

class BarDisplay
{
private:
	MyTransform* _transform;
	Color _filledPartColor;
	Color _emptyPartColor;
	int _currentPoints;
	int _maxPoints;
	bool _isVisible;

public:
	BarDisplay(Vector2 position,
		Vector2 size,
		Color filledPartColor,
		Color emptyPartColor,
		int currentPoints,
		int maxPoints);

	void SetPoints(int newCurrentPoints, int newMaxPoints);
	void Draw();
};
