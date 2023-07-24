#pragma once

#include <iostream>
#include "raylib.h"

class GameButton
{
private:
	Vector2 _position;
	Vector2 _size;
	Color _color;
	std::string _label;

public:
	GameButton(Vector2 position, Vector2 size, Color color, const std::string &label);
	void DrawButtonHitbox();
	void ChangeButtonLocation(Vector2 newPosition, Vector2 newSize);
	void ChangeButtonColor(Color newColor);
	void ChangeButtonLabel(const std::string& newLabel);
	Rectangle GetButtonHitbox();
};
