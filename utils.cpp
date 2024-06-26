#include "utils.h"

std::string GetGameTimeString()
{
    GAME_TIME = static_cast<int>(GetTime());

    int minutes = static_cast<int>(GAME_TIME) / 60;
    int seconds = static_cast<int>(GAME_TIME) % 60;

    std::string timeText = std::to_string(minutes) + ":" +
        (seconds < 10 ? "0" : "") + std::to_string(seconds);

    return timeText;
}

void DrawGameStatistics()
{
    std::string currentTime = "Time: " + GetGameTimeString();
    DrawText(currentTime.c_str(), 0, 0, 20, WHITE);

    std::string currentFPS = "FPS: " + std::to_string( GetFPS() );
    DrawText(currentFPS.c_str(), 0, 20, 20, WHITE);

    std::string clickScoreStr = "Gatocoins: " + std::to_string(CLICK_SCORE);
    DrawText(clickScoreStr.c_str(), 0, SCREEN_HEIGHT - 20, 20, WHITE);
}
