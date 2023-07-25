#include <iostream>
#include <string>
#include <vector>
#include "raylib.h"
#include "raymath.h"
#include "Wall.h"
#include "Character.h"
#include "Bullet.h"
#include "Bar.h"

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900

using std::cout;
using std::string;
using std::to_string;

const int mainButtonWight = 200;
const int mainButtonHeight = 50;

int clickScore = 0;

Character* mainCharacter;
Bar* mainCharacterBar;
Wall* mainButton;
Bar* mainButtonBar;

Texture2D mainCharacterSprite;
Texture2D mainBulletSprite;

int gameTime;

std::vector<Bullet> characterBullets;

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

    characterBullets.emplace_back(startPos, velocity, WHITE, 5.0f, 3.0f, 1);
}

void UpdateBullets()
{
    for (auto& bullet : characterBullets) {
        bullet.Update( GetTime() );
    }
}

void DrawCharacterBullets()
{
    for (auto& bullet : characterBullets) {
        bullet.DrawSprite(mainBulletSprite);
    }
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

void DrawCharacterElements()
{
    mainCharacter->DrawSprite(mainCharacterSprite);
    mainCharacterBar->DrawBase();

    mainCharacter->Move(mainButton->GetHitbox());

    Rectangle characterHitbox = mainCharacter->GetHitbox();
    Vector2 barPosition = { characterHitbox.x, characterHitbox.y - 10 };

    mainCharacterBar->SetPosition(barPosition);
}

void DrawMainButtonElements()
{
    mainButton->DrawHitbox();
    mainButtonBar->DrawBase();
    mainButton->ChangeColor(WHITE);

    Rectangle mainButtonHitbox = mainButton->GetHitbox();
    Vector2 barPosition = { mainButtonHitbox.x, mainButtonHitbox.y - 20 };

    mainButtonBar->SetPosition(barPosition);
}

void CheckBulletMainButtonCollision()
{
    for (auto& bullet : characterBullets) {
        if ( CheckCollisionCircleRec( bullet.GetCenter(), bullet.GetRadius(), mainButton->GetHitbox() ) )
        {
            if ( bullet.IsActive() )
            {
                mainButton->TakeDamage(1, mainButtonBar);
                clickScore++;
            }

            bullet.Delete();
        }
    }
}

void CheckShootingWithLMB()
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 startPos = { mainCharacter->GetHitbox().x, mainCharacter->GetHitbox().y };
        SpawnBullet(startPos, 500);
    }
}

void CheckMouseMainButtonCollision()
{
    if (CheckCollisionPointRec(GetMousePosition(), mainButton->GetHitbox()))
    {
        mainButton->ChangeColor(GRAY);
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

        DrawCharacterBullets();

        DrawMainButtonElements();

        DrawCharacterElements();

        DrawTextStrings();

        CheckShootingWithLMB();

        CheckMouseMainButtonCollision();

        CheckBulletMainButtonCollision();

        EndDrawing();
    }
}

int main(void)
{
    OpenWindow();

    SetTargetFPS(60);

    mainButton = new Wall( { SCREEN_WIDTH / 2 - mainButtonWight / 2, SCREEN_HEIGHT / 2 - mainButtonHeight / 2 },
        { mainButtonWight, mainButtonHeight }, WHITE, "Shoot Me", 100, 100 );
    mainButtonBar = new Bar( { SCREEN_WIDTH / 2 - mainButtonWight / 2, SCREEN_HEIGHT / 2 - mainButtonHeight / 2 - 20 },
        { mainButtonWight, 5.0f }, GREEN, DARKGRAY, 100, 100);

    mainCharacter = new Character( { 400.0f, 400.0f }, { 20.0f, 20.0f }, 250.0f, 100, 100 );
    mainCharacterBar = new Bar( { 400.0f, 390.0f }, { 40.0f, 5.0f }, GREEN, GRAY, 100, 100 );

    mainCharacterSprite = LoadTexture("textures/papa_cat.png");
    mainBulletSprite = LoadTexture("textures/kitigr.png");

    GameCycle();

    CloseWindow();

    return 0;
}
