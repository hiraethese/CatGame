#pragma once

#include <iostream>
#include <string>
#include "raylib.h"
#include "globals.h"

std::string GetGameTimeString();
void PrintCharacterPosition(Vector2 charPosition);
void DrawGameStatistics(Vector2 charPosition);
