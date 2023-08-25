#include "MyTransform.h"

MyTransform::MyTransform(Vector2 position, Vector2 size)
{
	_position = position;
	_size = size;
}

void MyTransform::SetPosition(Vector2 newPosition)
{
	_position = newPosition;
}

Vector2 MyTransform::GetPosition()
{
	return _position;
}

Vector2 MyTransform::GetSize()
{
	return _size;
}
