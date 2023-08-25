#include "Drawer.h"

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
	int fontSize = 20;
	int textWidth = MeasureText(label.c_str(), fontSize);
	Vector2 position = _transform->GetPosition();
	Vector2 size = _transform->GetSize();

	DrawText(label.c_str(), static_cast<int>( position.x - 0.5 * textWidth ),
		static_cast<int>( position.y - 0.5 * fontSize ),
		fontSize,
		BLACK);
}

void Drawer::DrawHitbox(Color color)
{
	if (_isVisible)
	{
		Vector2 trPosition = _transform->GetPosition();
		Vector2 trSize = _transform->GetSize();
		Rectangle recHitbox = { static_cast<int>( trPosition.x - 0.5 * trSize.x ),
			static_cast<int>( trPosition.y - 0.5 * trSize.y ),
			static_cast<int>( trSize.x ),
			static_cast<int>( trSize.y ) };

		DrawRectangleRec(recHitbox, color);
	}
}

void Drawer::Draw()
{
	if (_isVisible)
	{
		Vector2 trPosition = _transform->GetPosition();

		DrawTexture(_texture, static_cast<int>( trPosition.x - 0.5 * _texture.width ),
			static_cast<int>( trPosition.y - 0.5 * _texture.height ),
			WHITE);

		DrawHitbox(RED); // debug
	}
}

void Drawer::SetVisibility(bool isVisible)
{
	_isVisible = isVisible;
}
