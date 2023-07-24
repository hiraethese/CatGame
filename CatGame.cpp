#include <iostream>
#include <string>
#include <vector>
#include "raylib.h"
#include "raymath.h"
#include "GameButton.h"
#include "Character.h"
#include "Bullet.h"

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900

using std::cout;
using std::string;
using std::to_string;

const int mainButtonWight = 200;
const int mainButtonHeight = 50;

int clickScore = 0;

GameButton* mainButton;

Character* mainCharacter;

Texture2D mainCharacterSprite;
Texture2D mainBulletSprite;

int gameTime;

std::vector<Bullet> bullets;

void OpenWindow()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Cat Clicker");
}

void SpawnBullet(Vector2 startPos, float speed)
{
    Vector2 mousePos = GetMousePosition();
    Vector2 direction = Vector2Subtract(mousePos, startPos);
    direction = Vector2Normalize(direction);
    Vector2 velocity = { direction.x * speed, direction.y * speed };

    bullets.emplace_back(startPos, velocity, WHITE, 5.0f, 3.0f, 1);
}

void UpdateBullets()
{
    for (auto& bullet : bullets) {
        bullet.UpdateBullet( GetTime() );
    }
}

void DrawBullets()
{
    for (auto& bullet : bullets) {
        bullet.DrawBulletSprite(mainBulletSprite);
    }
}

void GameCycle()
{
    while (!WindowShouldClose())
    {
        gameTime = static_cast<int>( GetTime() );

        UpdateBullets();

        BeginDrawing();
        ClearBackground(BLACK);

        DrawBullets();

        string clickScoreStr = "Gatocoins: " + to_string(clickScore);
        DrawText(clickScoreStr.c_str(), 0, SCREEN_HEIGHT - 20, 20, WHITE);

        string currentFPS = "FPS: " + to_string( GetFPS() );
        DrawText(currentFPS.c_str(), 0, 0, 20, WHITE);

        string currentTime = "Time: " + to_string(gameTime);
        DrawText(currentTime.c_str(), 0, 20, 20, WHITE);

        mainButton->DrawButtonHitbox();
        mainButton->ChangeButtonColor(WHITE);

        mainCharacter->DrawCharacterSprite(mainCharacterSprite);
        mainCharacter->MoveCharacter(mainButton->GetButtonHitbox());

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            Vector2 startPos = { mainCharacter->GetCharacterHitbox().x, mainCharacter->GetCharacterHitbox().y };
            SpawnBullet(startPos, 5);
        }

        if (CheckCollisionPointRec(GetMousePosition(), mainButton->GetButtonHitbox()))
        {
            mainButton->ChangeButtonColor(GRAY);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                clickScore++;
            }
        }

        EndDrawing();
    }
}

int main(void)
{
    OpenWindow();

    SetTargetFPS(60);

    mainButton = new GameButton({ SCREEN_WIDTH / 2 - mainButtonWight / 2, SCREEN_HEIGHT / 2 - mainButtonHeight / 2 },
        { mainButtonWight, mainButtonHeight }, WHITE, "Shoot Me");

    mainCharacter = new Character({ 400.0f, 400.0f }, { 20.0f, 20.0f }, 5.0f, 100, 100);

    mainCharacterSprite = LoadTexture("textures/papa_cat.png");
    mainBulletSprite = LoadTexture("textures/kitigr.png");

    GameCycle();

    CloseWindow();

    return 0;
}
