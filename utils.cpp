#include "utils.h"

void DrawGameStatistics()
{
    std::string clickScoreStr = "Gatocoins: " + std::to_string(CLICK_SCORE);
    DrawText(clickScoreStr.c_str(), 0, SCREEN_HEIGHT - 20, 20, WHITE);

    std::string currentFPS = "FPS: " + std::to_string(GetFPS());
    DrawText(currentFPS.c_str(), 0, 0, 20, WHITE);

    std::string currentTime = "Time: " + std::to_string(GAME_TIME);
    DrawText(currentTime.c_str(), 0, 20, 20, WHITE);
}
