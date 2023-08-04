#include "Bar.h"

Bar::Bar(MyTransform* transform,
	Color filledPartColor,
	Color emptyPartColor,
	int currentPoints,
	int maxPoints)
{
	_transform = transform;
	_filledPartColor = filledPartColor;
	_emptyPartColor = emptyPartColor;
	_currentPoints = currentPoints;
	_maxPoints = maxPoints;
	_isVisible = true;
}

void Bar::Update(Vector2 newPosition, int newCurrentPoints, int newMaxPoints)
{
	_transform->SetPosition(newPosition);
	_currentPoints = newCurrentPoints;
	_maxPoints = newMaxPoints;
}

void Bar::Draw()
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
