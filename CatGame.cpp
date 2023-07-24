#include <iostream>
#include <string>
#include "raylib.h"
#include "GameButton.h"
#include "Character.h"

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900

using std::cout;
using std::string;
using std::to_string;

const int mainButtonWight = 200;
const int mainButtonHeight = 50;

int clickScore = 0;

GameButton* mainButton = new GameButton({ SCREEN_WIDTH / 2 - mainButtonWight / 2,
    SCREEN_HEIGHT / 2 - mainButtonHeight / 2 }, { mainButtonWight, mainButtonHeight }, WHITE, "Shoot Me");

Character* mainCharacter = new Character({ 400.0f, 400.0f }, { 20.0f, 20.0f }, 5.0f, 100, 100);

void GameCycle()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        string clickScoreStr = "Gatocoins: " + to_string(clickScore);
        DrawText(clickScoreStr.c_str(), 0, 0, 20, WHITE);

        string currentFPS = "FPS: " + to_string( GetFPS() );
        DrawText(currentFPS.c_str(), 0, SCREEN_HEIGHT - 20, 20, WHITE);

        mainButton->DrawButton();
        mainButton->ChangeButtonColor(WHITE);

        mainCharacter->DrawCharacter();
        mainCharacter->MoveCharacter(mainButton->GetButtonRectangle());

        if (CheckCollisionPointRec(GetMousePosition(), mainButton->GetButtonRectangle()))
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

void OpenWindow()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Cat Clicker");
}

int main(void)
{
    OpenWindow();

    SetTargetFPS(60);

    GameCycle();

    CloseWindow();

    return 0;
}
