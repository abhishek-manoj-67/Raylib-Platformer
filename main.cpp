#include <iostream>
#include <raylib.h>

int main () {

    const short SCREEN_WIDTH = 800, SCREEN_HEIGHT = 600;
    const unsigned char FPS = 60;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib Window");

    SetExitKey(KEY_NULL);

    SetTargetFPS(FPS);

    while (WindowShouldClose() == false){
        BeginDrawing();
            ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
}