#include "SpriteDrawer.h"

SpriteDrawer::SpriteDrawer(bool isVisibile, Texture2D texture, MyTransform* transform)
{
	_isVisible = isVisibile;
	_texture = texture;
	_transform = transform;
}

void SpriteDrawer::DrawHitbox(Color color)
{
	if (_isVisible)
	{
		DrawRectangleRec(_transform->GetHitbox(), color);
	}
}

void SpriteDrawer::Draw()
{
	if (_isVisible)
	{
		Vector2 position = _transform->GetPosition();
		DrawTexture(_texture, static_cast<int>(position.x),
			static_cast<int>(position.y), WHITE);
	}
}
