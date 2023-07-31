#include "Drawer.h"
#include <string>

Drawer::Drawer(bool isVisibile,
	Texture2D texture,
	MyTransform* transform)
{
	_isVisible = isVisibile;
	_texture = texture;
	_transform = transform;
}

void Drawer::DrawLabel(std::string label)
{
	Vector2 position = _transform->GetPosition();
	Vector2 size = _transform->GetSize();
	DrawText(label.c_str(), static_cast<int>(position.x + size.x / 4.0f),
		static_cast<int>(position.y + size.y / 4.0f), 20, BLACK);
}

void Drawer::DrawHitbox(Color color)
{
	if (_isVisible)
	{
		DrawRectangleRec(_transform->GetRectangle(), color);
	}
}

void Drawer::Draw()
{
	if (_isVisible)
	{
		Vector2 position = _transform->GetPosition();
		DrawTexture(_texture, static_cast<int>(position.x),
			static_cast<int>(position.y), WHITE);
	}
}

void Drawer::SetVisibility(bool isVisible)
{
	_isVisible = isVisible;
}
