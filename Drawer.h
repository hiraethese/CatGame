#pragma once

#include <string>
#include "raylib.h"
#include "MyTransform.h"

class Drawer
{
private:
	bool _isVisible;
	Texture2D _texture;
	MyTransform* _transform;

public:
	Drawer(bool isVisibile,
		Texture2D texture,
		MyTransform* transform);

	void DrawLabel(std::string _label);
	void DrawHitbox(Color color);
	void Draw();
	void SetVisibility(bool isVisible);
};
