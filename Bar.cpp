#include "Bar.h"

Bar::Bar(Vector2 size, Color filledPartColor,
	Color emptyPartColor, int maxPoints, int currentPoints)
{
	_size = size;
	_filledPartColor = filledPartColor;
	_emptyPartColor = emptyPartColor;
	_maxPoints = maxPoints;
	_currentPoints = currentPoints;
	_isVisible = true;
}

void Bar::DrawBase(Vector2 position)
{	
	if (_isVisible)
	{
		float currentPointsPercentage = static_cast<float>(_currentPoints) / static_cast<float>(_maxPoints);
		float currentPointsWidth = _size.x * currentPointsPercentage;

		Rectangle emptyBar = { position.x, position.y, _size.x, _size.y };
		Rectangle filledBar = { position.x, position.y, currentPointsWidth, _size.y };

		DrawRectangleRec( emptyBar, _emptyPartColor );
		DrawRectangleRec( filledBar, _filledPartColor );
	}
}

void Bar::SetPoints(int newMaxPoints, int newCurrentPoints)
{
	_maxPoints = newMaxPoints;
	_currentPoints = newCurrentPoints;
}
