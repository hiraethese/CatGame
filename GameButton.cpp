#include "GameButton.h"
#include "raylib.h"

GameButton::GameButton(Vector2 position, Vector2 size,
	Color color, const std::string& label)
{
	_position = position;
	_size = size;
	_color = color;
	_label = label;
}

void GameButton::DrawButton()
{
	DrawRectangleRec( GetButtonRectangle(), _color );
	DrawText( _label.c_str(), static_cast<int>(_position.x + _size.x / 4.0f),
		static_cast<int>(_position.y + _size.y / 4.0f), 20, BLACK);
}

void GameButton::ChangeButtonLocation(Vector2 position, Vector2 size)
{
	_position = position;
	_size = size;
}

void GameButton::ChangeButtonColor(Color newColor)
{
	_color = newColor;
}

void GameButton::ChangeButtonLabel(const std::string& newLabel)
{
	_label = newLabel;
}

Rectangle GameButton::GetButtonRectangle()
{
	Rectangle button = { static_cast<float>(_position.x), static_cast<float>(_position.y),
		static_cast<float>(_size.x), static_cast<float>(_size.y) };
	return button;
}
