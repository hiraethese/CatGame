#include <iostream>
#include <string>
#include <vector>
#include "global.h"
#include "raylib.h"
#include "raymath.h"
#include "Wall.h"
#include "Character.h"
#include "Bullet.h"
#include "Bar.h"
#include "RandomGenerator.h"

float SCREEN_WIDTH = 1280.0f;
float SCREEN_HEIGHT = 720.0f;

using std::cout;
using std::string;
using std::to_string;

const int mainButtonWight = 200;
const int mainButtonHeight = 50;

int clickScore = 0;

Character* mainCharacter;
Wall* mainButton;

Texture2D mainCharacterSprite;
Texture2D mainBulletSprite;
Texture2D enemySprite;

int gameTime;

std::vector<Bullet*> bullets;
std::vector<Character*> enemies;

void SpawnSimpleEnemy(Vector2 startPos)
{
    Vector2 size = { 100.0f, 100.0f };
    Character* enemy = new Character(startPos, size, 200.0f, 100, 100, enemySprite);

    enemies.push_back(enemy);
}

void SpawnBulletInMouseDirection(Vector2 startPos, Vector2 targetPos)
{
    Vector2 size = { 100.0f, 100.0f };
    Bullet* bullet = new Bullet(startPos, targetPos, size, 200.0f, mainCharacterSprite);

    bullets.push_back(bullet);
}

void DrawTextStrings()
{
    string clickScoreStr = "Gatocoins: " + to_string(clickScore);
    DrawText(clickScoreStr.c_str(), 0, SCREEN_HEIGHT - 20, 20, WHITE);

    string currentFPS = "FPS: " + to_string(GetFPS());
    DrawText(currentFPS.c_str(), 0, 0, 20, WHITE);

    string currentTime = "Time: " + to_string(gameTime);
    DrawText(currentTime.c_str(), 0, 20, 20, WHITE);
}

void CheckShootingWithLMB()
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 startPos = mainCharacter->GetTransform()->GetPosition();
        Vector2 mousePos = GetMousePosition();
        SpawnBulletInMouseDirection(startPos, mousePos);
    }
}

void GameCycle()
{
    while (!WindowShouldClose())
    {
        gameTime = static_cast<int>( GetTime() );

        BeginDrawing(); // DRAW SCREEN
        ClearBackground(BLACK);

        mainButton->UpdateButton();

        mainCharacter->UpdateProtagonist( mainButton->GetTransform()->GetRectangle() );

        for (auto& enemy : enemies) {
            enemy->UpdateEnemy( mainCharacter->GetTransform()->GetPosition() );
        }

        for (auto& bullet : bullets) {
            bullet->Update();
        }

        DrawTextStrings();

        CheckShootingWithLMB();

        EndDrawing();
    }
}

void OpenWindow()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "CatGame");
}

int main(void)
{
    OpenWindow();

    SetTargetFPS(-1);

    mainCharacterSprite = LoadTexture("textures/Sprite-0015main.png");
    mainBulletSprite = LoadTexture("textures/Sprite-0015main.png");
    enemySprite = LoadTexture("textures/Sprite-00007.png");

    mainCharacter = new Character( { 400.0f, 400.0f }, { 20.0f, 20.0f }, 250.0f, 100, 100, mainCharacterSprite);

    mainButton = new Wall( { SCREEN_WIDTH / 2 - mainButtonWight / 2, SCREEN_HEIGHT / 2 - mainButtonHeight / 2 },
        { mainButtonWight, mainButtonHeight }, WHITE, 100, 100, mainCharacterSprite );

    SpawnSimpleEnemy( GenerateRandomLocationOutsideScreen() );

    GameCycle();

    CloseWindow();

    return 0;
}
