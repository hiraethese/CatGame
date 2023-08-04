#include "Bullet.h"

Bullet::Bullet(float speed,
	b2World* world,
	Vector2 position,
	Vector2 size,
	Vector2 direction,
	Texture2D texture)
{
	_transform = new MyTransform(world, position, size);
	_physicsBody = new PhysicsBody(speed, world, _transform);
	_sprite = new Drawer(true, texture, _transform);
	_direction = direction;
	_isGarbage = false;
}

void Bullet::Update()
{
	_physicsBody->MoveInDirection(_direction);

	_sprite->Draw();

	Vector2 position = _physicsBody->GetTransform()->GetPosition();
	if (position.x < 0 || position.x > SCREEN_WIDTH ||
		position.y < 0 || position.y > SCREEN_HEIGHT)
	{
		_isGarbage = true;
	}
}

PhysicsBody* Bullet::GetPhysicsBody()
{
	return _physicsBody;
}

Drawer* Bullet::GetDrawer()
{
	return _sprite;
}

bool Bullet::IsGarbage()
{
	return _isGarbage;
}
