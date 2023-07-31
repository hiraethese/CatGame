#include "RandomGenerator.h"
#include "global.h"

Vector2 GenerateRandomLocationOutsideScreen()
{
    Vector2 location = { 0, 0 };
    int side = GetRandomValue(0, 3);

    switch (side) {
    case 0:
        location.x = -50;
        location.y = static_cast<float>(GetRandomValue(0, SCREEN_HEIGHT));
        break;
    case 1:
        location.x = SCREEN_WIDTH + 50;
        location.y = static_cast<float>(GetRandomValue(0, SCREEN_HEIGHT));
        break;
    case 2:
        location.x = static_cast<float>(GetRandomValue(0, SCREEN_WIDTH));
        location.y = -50;
        break;
    case 3:
        location.x = static_cast<float>(GetRandomValue(0, SCREEN_WIDTH));
        location.y = SCREEN_HEIGHT + 50;
        break;
    }

    return location;
}
