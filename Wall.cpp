#include "Wall.h"

Wall::Wall(b2World* world,
	Vector2 position,
	Vector2 size,
	Color color,
	Texture2D texture)
{
	_transform = new MyTransform(position, size);
	_physicsBody = new PhysicsBody(world, _transform, 0.0f);
	_sprite = new Drawer(true, texture, _transform);
}

void Wall::UpdateButton()
{
	_sprite->DrawHitbox(WHITE);

	_sprite->DrawLabel("Shoot Me");
}

MyTransform* Wall::GetTransform() 
{
	return _transform;
}

Drawer* Wall::GetDrawer()
{
	return _sprite;
}

PhysicsBody* Wall::GetPhysicsBody()
{
	return _physicsBody;
}
