#include <vector>
#include "utils.h"
#include "randomGenerator.h"
#include "Character.h"
#include "Skill.h"
#include "Wall.h"
#include "Bullet.h"
#include "Spawner.h"
#include "skillLibrary.h"

float SCREEN_WIDTH = 1280.0f;
float SCREEN_HEIGHT = 720.0f;

int GAME_TIME = 0;
int CLICK_SCORE = 0;

Texture2D mainCharacterSprite;
Texture2D simpleEnemySprite;
Texture2D mainBulletSprite;
Texture2D mainButtonSprite;

Character* mainCharacter;
Wall* mainButton;
Spawner* spawner;

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "CatGame");

    SetTargetFPS(-1);

    mainCharacterSprite = LoadTexture("textures/Sprite-0015main.png");
    simpleEnemySprite = LoadTexture("textures/Sprite-00007.png");
    mainBulletSprite = LoadTexture("textures/Sprite-0015main.png");
    mainButtonSprite = {};

    mainCharacter = new Character( { 400.0f, 400.0f }, { 20.0f, 20.0f },
        250.0f, 100, 100, mainCharacterSprite);
    mainCharacter->GetSkill()->ChangeSkill("canShootWithLMB", true);
    mainCharacter->GetSkill()->ChangeSkill("canRandomlySpawnEnemy", true);

    mainButton = new Wall( { SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 25 },
        { 200, 50 }, WHITE, 100, 100, mainCharacterSprite );
    Rectangle mainButtonRec = mainButton->GetTransform()->GetRectangle();

    spawner = new Spawner();

    while (!WindowShouldClose())
    {
        GAME_TIME = static_cast<int>(GetTime());

        BeginDrawing();
        ClearBackground(BLACK);

        mainButton->UpdateButton();
        mainCharacter->UpdateProtagonist(spawner);
        spawner->UpdateEnemies( mainCharacter->GetTransform()->GetPosition() );
        spawner->UpdateBullets();

        DrawGameStatistics();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
