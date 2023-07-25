#include "Bar.h"

Bar::Bar(Vector2 position, Vector2 size, Color filledPartColor,
	Color emptyPartColor, int maxPoints, int currentPoints)
{
	_position = position;
	_size = size;
	_filledPartColor = filledPartColor;
	_emptyPartColor = emptyPartColor;
	_maxPoints = maxPoints;
	_currentPoints = currentPoints;
	_visibility = true;
}

void Bar::DrawBaseBar()
{	
	float currentPointsPercentage = static_cast<float>(_currentPoints) / static_cast<float>(_maxPoints);
	float currentPointsWidth = _size.x * currentPointsPercentage;

	DrawRectangle( _position.x, _position.y,
		_size.x, _size.y, _emptyPartColor);
	DrawRectangle( _position.x, _position.y,
		currentPointsWidth, _size.y, _filledPartColor);
}
