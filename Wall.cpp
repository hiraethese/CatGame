#include "Wall.h"

Wall::Wall(Vector2 position,
	Vector2 size,
	Color color,
	int currentHealth,
	int maxHealth,
	Texture2D texture)
{
	_transform = new MyTransform(position, size);
	_sprite = new Drawer(true, texture, _transform);
	_health = new Health(currentHealth, maxHealth, false, false);

	Vector2 healthBarLocation = Vector2Add(_transform->GetPosition(), { 0.0f, -10.0f });
	_healthBar = new Bar(healthBarLocation, { 200.0f, 5.0f },
		GREEN, GRAY, _health->GetCurrentHealth(), _health->GetMaxHealth());
}

void Wall::UpdateButton()
{
	Vector2 healthBarLocation = Vector2Add(_transform->GetPosition(), { 0.0f, -10.0f });
	Health* health = GetHealth();
	_healthBar->Update(healthBarLocation,
		health->GetCurrentHealth(), health->GetMaxHealth());

	_sprite->DrawHitbox(WHITE);
	_sprite->DrawLabel("Shoot Me");
	_healthBar->Draw();
}

MyTransform* Wall::GetTransform()
{
	return _transform;
}

Drawer* Wall::GetDrawer()
{
	return _sprite;
}

Health* Wall::GetHealth()
{
	return _health;
}
