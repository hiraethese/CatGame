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

Rectangle MyTransform::GetHitbox()
{
	return { _position.x, _position.y, _size.x, _size.y };
}

Vector2 MyTransform::GetPosition()
{
	return _position;
}

Vector2 MyTransform::GetSize()
{
	return _size;
}


