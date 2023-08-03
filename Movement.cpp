#include "Movement.h"

Movement::Movement(float speed,
	MyTransform* transform)
{
	_speed = speed;
	_transform = transform;
}

void Movement::MoveWithKeyboard()
{
	Vector2 position = _transform->GetPosition();
	Vector2 size = _transform->GetSize();
	Vector2 direction = { 0.0f, 0.0f };

	if (IsKeyDown(KEY_W)) {
		direction.y -= 1.0f;
	}
	if (IsKeyDown(KEY_S)) {
		direction.y += 1.0f;
	}
	if (IsKeyDown(KEY_A)) {
		direction.x -= 1.0f;
	}
	if (IsKeyDown(KEY_D)) {
		direction.x += 1.0f;
	}

	direction = Vector2Normalize(direction);

	position.x += direction.x * _speed * GetFrameTime();
	position.y += direction.y * _speed * GetFrameTime();

	if (position.x < 0) position.x = 0;
	if (position.x + size.x > GetScreenWidth())
		position.x = GetScreenWidth() - size.x;
	if (position.y < 0) position.y = 0;
	if (position.y + size.y > GetScreenHeight())
		position.y = GetScreenHeight() - size.y;

	_transform->SetPosition(position);
}

void Movement::MoveInDirection(Vector2 direction)
{
	Vector2 position = _transform->GetPosition();

	position.x += direction.x * _speed * GetFrameTime();
	position.y += direction.y * _speed * GetFrameTime();

	_transform->SetPosition(position);
}

void Movement::ChaseTarget(Vector2 target)
{
	Vector2 position = _transform->GetPosition();
	Vector2 direction = Vector2Subtract(target, position);
	direction = Vector2Normalize(direction);
	float distanceToTarget = Vector2Distance(target, position);

	if ( distanceToTarget > _speed * GetFrameTime() )
	{
		position.x += direction.x * _speed * GetFrameTime();
		position.y += direction.y * _speed * GetFrameTime();
	}
	else
	{
		position = target;
	}

	_transform->SetPosition(position);
}

void Movement::SetSpeed(float newSpeed)
{
	_speed = newSpeed;
}
