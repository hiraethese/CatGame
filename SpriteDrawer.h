#pragma once

#include "raylib.h"
#include "MyTransform.h"

class SpriteDrawer
{
private:
	bool _isVisible;
	Texture2D _texture;
	MyTransform* _transform;

public:
	SpriteDrawer(bool isVisibile, Texture2D texture, MyTransform* transform);
	void DrawHitbox(Color color);
	void Draw();
};
