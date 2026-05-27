#include <iostream>
#include <raylib.h>

#include "Vector2D.hpp"

int main () {
    // setup
    const short SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;
    const unsigned char FPS = 60;

    // boilerplate
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib Window");
    SetExitKey(KEY_NULL);
    SetTargetFPS(FPS);

    // variables
    Vec2 position = Vec2(0, 0);
    Vec2 velocity = Vec2(0, 0);

    Vec2 direction = Vec2(0, 0);

    double speed = 10;

    while (WindowShouldClose() == false){
        // direction input
        direction.zero();

        // update
        position += direction;

        std::cout << position << "\n";

        // render
        BeginDrawing();
            ClearBackground(BLACK);
            DrawCircle(position.x, position.y, 3, WHITE);
        EndDrawing();
    }

    CloseWindow();
}