#include "BarDisplay.h"

BarDisplay::BarDisplay(Vector2 position,
	Vector2 size,
	Color filledPartColor,
	Color emptyPartColor,
	int currentPoints,
	int maxPoints)
{
	_transform = new MyTransform(position, size);;
	_filledPartColor = filledPartColor;
	_emptyPartColor = emptyPartColor;
	_currentPoints = currentPoints;
	_maxPoints = maxPoints;
	_isVisible = true;
}

void BarDisplay::SetPoints(int newCurrentPoints, int newMaxPoints)
{
	_currentPoints = newCurrentPoints;
	_maxPoints = newMaxPoints;
}

void BarDisplay::Draw()
{	
	if (_isVisible)
	{
		Vector2 position = _transform->GetPosition();
		Vector2 size = _transform->GetSize();

		float currentPointsPercentage = static_cast<float>(_currentPoints) / static_cast<float>(_maxPoints);
		float currentPointsWidth = size.x * currentPointsPercentage;

		Rectangle emptyBar = { position.x, position.y, size.x, size.y };
		Rectangle filledBar = { position.x, position.y, currentPointsWidth, size.y };

		DrawRectangleRec( emptyBar, _emptyPartColor );
		DrawRectangleRec( filledBar, _filledPartColor );
	}
}
