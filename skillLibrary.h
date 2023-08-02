#ifndef SKILL_BOOK_H
#define SKILL_BOOK_H

#include "raylib.h"
#include "globals.h"
#include "random_generator.h"
#include "Spawner.h"

void ShootWithLMB(Spawner* spawner, Vector2 startPos);
void RandomlySpawnEnemy(Spawner* spawner);

#endif
