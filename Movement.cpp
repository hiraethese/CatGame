#include "Movement.h"
#include "MyTransform.h"
#include "raymath.h"

Movement::Movement(float speed, MyTransform* transform)
{
	_speed = speed;
	_transform = transform;
}

void Movement::UpdateLocation(Vector2 target)
{
	Vector2 position = _transform->GetPosition();
	Vector2 direction = Vector2Subtract(target, position);
	direction = Vector2Normalize(direction);
	Vector2 velocity = { direction.x * _speed, direction.y * _speed };

	position.x += velocity.x * GetFrameTime();
	position.y += velocity.y * GetFrameTime();

	_transform->SetPosition(position);
}

void Movement::Move(Rectangle recCollision)
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

	if (CheckCollisionRecs(_transform->GetHitbox(), recCollision))
	{
		if (direction.x > 0 && position.x < recCollision.x)
		{
			position.x = recCollision.x - size.x;
		}
		else if (direction.x < 0 && position.x + size.x > recCollision.x + recCollision.width)
		{
			position.x = recCollision.x + recCollision.width;
		}

		if (direction.y > 0 && position.y < recCollision.y)
		{
			position.y = recCollision.y - size.y;
		}
		else if (direction.y < 0 && position.y + size.y > recCollision.y + recCollision.height)
		{
			position.y = recCollision.y + recCollision.height;
		}
	}

	_transform->SetPosition(position);
}

void Movement::SetSpeed(float newSpeed)
{
	_speed = newSpeed;
}
