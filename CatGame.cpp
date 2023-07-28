#include <iostream>
#include <string>
#include <vector>
#include "raylib.h"
#include "raymath.h"
#include "Wall.h"
#include "Character.h"
#include "Bullet.h"
#include "Bar.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

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

std::vector<Bullet> bullets;

std::vector<Character> enemies;

Vector2 GenerateRandomLocationOutsideScreen()
{
    Vector2 location = { 0, 0 };
    int side = GetRandomValue(0, 3);

    switch (side) {
    case 0:
        location.x = -50;
        location.y = static_cast<float>( GetRandomValue(0, SCREEN_HEIGHT) );
        break;
    case 1:
        location.x = SCREEN_WIDTH + 50;
        location.y = static_cast<float>( GetRandomValue(0, SCREEN_HEIGHT) );
        break;
    case 2:
        location.x = static_cast<float>( GetRandomValue(0, SCREEN_WIDTH) );
        location.y = -50;
        break;
    case 3:
        location.x = static_cast<float>( GetRandomValue(0, SCREEN_WIDTH) );
        location.y = SCREEN_HEIGHT + 50;
        break;
    }

    return location;
}

void SpawnSimpleEnemie(Vector2 startPos)
{
    Vector2 size = { 100.0f, 100.0f };
    enemies.emplace_back( startPos, size, 200.0f, 100, 100, enemySprite );

    // mainEnemyBar = new Bar(startPos, { 40.0f, 5.0f }, GREEN, DARKGRAY, 100, 100 );
}

void UpdateEnemiesLocation(Vector2 target)
{
    for (auto& enemie : enemies) {
        enemie.GetMovement()->UpdateLocation(target);
        /*Vector2 enemyPosition = enemie.GetTransform()->GetPosition();*/
        // mainEnemyBar->SetPosition( { enemyPosition.x, enemyPosition.y - 50 } );
    }
}

void DrawEnemies()
{
    for (auto& enemie : enemies) {
        enemie.GetDrawer()->Draw();
        // enemie.DrawHitbox(WHITE); // hitbox
        // mainEnemyBar->DrawBase();
    }
}

void SpawnBulletInMouseDirection(Vector2 startPos, float speed)
{
    Vector2 mousePos = GetMousePosition();
    Vector2 direction = Vector2Subtract(mousePos, startPos);
    direction = Vector2Normalize(direction);
    Vector2 velocity = { direction.x * speed, direction.y * speed };

    bullets.emplace_back( startPos, velocity, 5.0f, 3.0f, 1 );
}

void UpdateBulletsLocation()
{
    for (auto& bullet : bullets) {
        bullet.UpdateLocation( GetTime() );
    }
}

void DrawCharacterBullets()
{
    for (auto& bullet : bullets) {
        bullet.DrawSprite(mainBulletSprite);
        // bullet.DrawHitbox(); // hitbox
    }
}

void UpdateMainButtonLocation()
{
    Rectangle mainButtonHitbox = mainButton->GetHitbox();
    Vector2 barPosition = { mainButtonHitbox.x, mainButtonHitbox.y - 20 };
    // mainButtonBar->SetPosition(barPosition);
}

void DrawMainButton()
{
    mainButton->DrawHitbox(); // hitbox
    
    mainButton->ChangeColor(WHITE);

    // mainButtonBar->DrawBase();
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

void CheckBulletEnemyCollision()
{
    for (auto& bullet : bullets)
    {
        for (auto& enemy : enemies)
        {
            if ( CheckCollisionCircleRec( bullet.GetCenter(), bullet.GetRadius(), enemy.GetTransform()->GetHitbox() ) )
            {
                if ( bullet.IsActive() )
                {
                    enemy.GetHealth()->TakeDamage(1);
                    clickScore++;
                }

                bullet.Delete();
            }
        }
    }
}

void CheckBulletMainButtonCollision()
{
    for (auto& bullet : bullets) {
        if ( CheckCollisionCircleRec( bullet.GetCenter(), bullet.GetRadius(), mainButton->GetHitbox() ) )
        {
            if ( bullet.IsActive() )
            {
                mainButton->TakeDamage(1);
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
        Vector2 startPos = mainCharacter->GetTransform()->GetPosition();
        SpawnBulletInMouseDirection(startPos, 500);
    }
}

void GameCycle()
{
    while (!WindowShouldClose())
    {
        gameTime = static_cast<int>( GetTime() );

        UpdateBulletsLocation();

        UpdateMainButtonLocation();

        UpdateEnemiesLocation( mainCharacter->GetTransform()->GetPosition() );

        BeginDrawing(); // DRAW SCREEN
        ClearBackground(BLACK);

        DrawCharacterBullets();

        DrawMainButton();

        DrawEnemies();

        mainCharacter->Update( mainButton->GetHitbox() );

        DrawTextStrings();

        CheckShootingWithLMB();

        CheckBulletMainButtonCollision();
        
        CheckBulletEnemyCollision();

        EndDrawing();
    }
}

void OpenWindow()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Cat Game");
}

int main(void)
{
    OpenWindow();

    SetTargetFPS(-1);

    mainButton = new Wall( { SCREEN_WIDTH / 2 - mainButtonWight / 2, SCREEN_HEIGHT / 2 - mainButtonHeight / 2 },
        { mainButtonWight, mainButtonHeight }, WHITE, "Shoot Me", 100, 100 );
    /*mainButtonBar = new Bar( { SCREEN_WIDTH / 2 - mainButtonWight / 2, SCREEN_HEIGHT / 2 - mainButtonHeight / 2 - 20 },
        { mainButtonWight, 5.0f }, GREEN, DARKGRAY, 100, 100);*/

    /*mainCharacterBar = new Bar( { 400.0f, 350.0f }, { 40.0f, 5.0f }, GREEN, GRAY, 100, 100 );*/

    mainCharacterSprite = LoadTexture("textures/Sprite-0015main.png");
    mainBulletSprite = LoadTexture("textures/Sprite-0015main.png");
    enemySprite = LoadTexture("textures/Sprite-00007.png");

    mainCharacter = new Character( { 400.0f, 400.0f }, { 20.0f, 20.0f }, 250.0f, 100, 100, mainCharacterSprite);

    SpawnSimpleEnemie( GenerateRandomLocationOutsideScreen() );

    GameCycle();

    CloseWindow();

    return 0;
}
