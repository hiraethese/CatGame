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
	_isVisible = true;
	_isInvunerable = false;
	_isDestroyed = false;
}

void Wall::DrawHitbox()
{
	DrawRectangleRec( GetHitbox(), _color );
	DrawText( _label.c_str(), static_cast<int>(_position.x + _size.x / 4.0f),
		static_cast<int>(_position.y + _size.y / 4.0f), 20, BLACK);
}

void Wall::ChangeLocation(Vector2 position, Vector2 size)
{
	_position = position;
	_size = size;
}

void Wall::ChangeColor(Color newColor)
{
	_color = newColor;
}

void Wall::ChangeLabel(const std::string& newLabel)
{
	_label = newLabel;
}

void Wall::SetInvulnerability(bool isInvunerable)
{
	_isInvunerable = isInvunerable;
}

void Wall::TakeDamage(int damagePoints, Bar* healthBar)
{
	if (!_isInvunerable)
	{
		_currentHealth -= damagePoints;

		if (_currentHealth <= 0)
		{
			_currentHealth = 0;
			_isDestroyed = true;
		}

		healthBar->SetPoints(_maxHealth, _currentHealth);
	}
}

void Wall::HealDamage(int healPoints, Bar* healthBar)
{
	_currentHealth += healPoints;

	if (_currentHealth >= _maxHealth)
	{
		_currentHealth = _maxHealth;
	}
}

Rectangle Wall::GetHitbox()
{
	Rectangle button = { _position.x, _position.y, _size.x, _size.y };
	return button;
}

int Wall::GetCurrentHealth()
{
	return _currentHealth;
}

int Wall::GetMaxHealth()
{
	return _maxHealth;
}
