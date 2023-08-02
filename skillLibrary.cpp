#include "skillLibrary.h"

void ShootWithLMB(Spawner* spawner, Vector2 startPos)
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePos = GetMousePosition();

        spawner->SpawnBulletWithTarget(startPos, mousePos, mainBulletSprite);
    }
}

void RandomlySpawnEnemy(Spawner* spawner)
{
    if (IsKeyPressed(KEY_E))
    {
        Vector2 startPos = GenerateRandomLocationOutsideScreen();

        spawner->SpawnSimpleEnemy(startPos, simpleEnemySprite);
    }
}
