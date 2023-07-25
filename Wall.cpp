#include "Wall.h"
#include "raylib.h"

Wall::Wall(Vector2 position, Vector2 size, Color color,
	const std::string& label, int currentHealth, int maxHealth)
{
	_position = position;
	_size = size;
	_color = color;
	_label = label;
	_currentHealth = currentHealth;
	_maxHealth = maxHealth;
	_visibility = true;
	_isDead = false;
}

void Wall::DrawWallHitbox()
{
	DrawRectangleRec( GetWallHitbox(), _color );
	DrawText( _label.c_str(), static_cast<int>(_position.x + _size.x / 4.0f),
		static_cast<int>(_position.y + _size.y / 4.0f), 20, BLACK);
}

void Wall::ChangeWallLocation(Vector2 position, Vector2 size)
{
	_position = position;
	_size = size;
}

void Wall::ChangeWallColor(Color newColor)
{
	_color = newColor;
}

void Wall::ChangeWallLabel(const std::string& newLabel)
{
	_label = newLabel;
}

Rectangle Wall::GetWallHitbox()
{
	Rectangle button = { _position.x, _position.y, _size.x, _size.y };
	return button;
}
