#include "Character.h"
#include "Bar.h"
#include "raymath.h"
#include <cmath>

Character::Character(Vector2 position,
	Vector2 size,
	float speed,
	int currentHealth,
	int maxHealth,
	Texture2D texture)
{
	_transform = new MyTransform(position, size);
	_movement = new Movement(speed, _transform);
	_drawer = new SpriteDrawer(true, texture, _transform);
	_health = new Health(currentHealth, maxHealth, false, false);
	_healthBar = new Bar({ 40.0f, 5.0f }, GREEN, GRAY, 100, 100);
}

void Character::Update(Rectangle collision)
{
	_movement->Move(collision);
	_drawer->Draw();
}

MyTransform* Character::GetTransform()
{
	return _transform;
}

SpriteDrawer* Character::GetDrawer()
{
	return _drawer;
}

Movement* Character::GetMovement()
{
	return _movement;
}

Health* Character::GetHealth()
{
	return _health;
}
