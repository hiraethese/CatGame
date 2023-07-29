#include "Character.h"
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
	_drawer = new SpriteDrawer(true, texture, _transform);
	_movement = new Movement(speed, _transform);
	_health = new Health(currentHealth, maxHealth, false, false);
	_healthBar = new BarDisplay(_transform->GetPosition(), _transform->GetSize(),
		GREEN, GRAY, _health->GetCurrentHealth(), _health->GetMaxHealth());
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
