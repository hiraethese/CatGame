#include "Bullet.h"

Bullet::Bullet(Vector2 position,
	Vector2 target,
	Vector2 size,
	float speed,
	Texture2D texture)
{
	_transform = new MyTransform(position, size);
	_sprite = new Drawer(true, texture, _transform);
	_movement = new Movement(speed, _transform);
	_direction = Vector2Normalize( Vector2Subtract(target, position) );
	_isGarbage = false;
}

void Bullet::Update()
{
	_movement->MoveInDirection(_direction);
	Vector2 position = _transform->GetPosition();

	if (position.x > GetScreenWidth() || position.x < 0 ||
		position.y > GetScreenHeight() || position.y < 0)
	{
		_sprite->SetVisibility(false);
	}

	_sprite->Draw();
}

MyTransform* Bullet::GetTransform()
{
	return _transform;
}

Drawer* Bullet::GetDrawer()
{
	return _sprite;
}

Movement* Bullet::GetMovement()
{
	return _movement;
}

bool Bullet::IsGarbage()
{
	return _isGarbage;
}
