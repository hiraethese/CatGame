#pragma once

#include "MyTransform.h"

class Bar
{
private:
	MyTransform* _transform;
	Color _filledPartColor;
	Color _emptyPartColor;
	int _currentPoints;
	int _maxPoints;
	bool _isVisible;

public:
	Bar(Vector2 position,
		Vector2 size,
		Color filledPartColor,
		Color emptyPartColor,
		int currentPoints,
		int maxPoints);

	void Update(Vector2 newPosition, int newCurrentPoints, int newMaxPoints);
	void Draw();
};
