#include "skillLibrary.h"

void ShootWithLMB(Spawner* spawner, Vector2 startPos)
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePos = GetMousePosition();

        Vector2 direction = Vector2Normalize( Vector2Subtract(mousePos, startPos) );

        spawner->SpawnBulletWithDirection( startPos, direction, mainBulletSprite );
    }
}

void RandomlySpawnEnemy(Spawner* spawner)
{
    if (IsKeyPressed(KEY_E))
    {
        Vector2 startPos = GenerateRandomLocationOutsideScreen();

        spawner->SpawnSimpleEnemy( startPos, simpleEnemySprite );
    }
}
