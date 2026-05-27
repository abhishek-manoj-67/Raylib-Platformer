#include <iostream>
#include <raylib.h>

#include "Vector2D.hpp"

// formula to find peak jump height (floor x's):
// vx-\frac{a}{2}x^{2}+\frac{a}{2}x

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
    Vec2 acceleration = Vec2(0, 1);

    Vec2 direction = Vec2(0, 0);

    double speed = 10;

    double groundThreshold = SCREEN_HEIGHT - 100;
    bool grounded = 0;

    unsigned char jumpHeight = 10;
    bool isJumping = 0;

    while (WindowShouldClose() == false){
        // direction input
        direction.zero();

        isJumping = (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP));
        // if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) { direction.y += 1; }
        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) { direction.x -= 1; }
        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) { direction.x += 1; }


        velocity.x = direction.normalize().x * speed;

        // update
        position += velocity;
        velocity += acceleration;

        // if (!isJumping && grounded) {
        //     velocity.y = -jumpHeight;
        // } else if (!isJumping && !grounded && velocity.y < 0) {
        //     velocity.y = 0;
        // }

        if (position.y >= groundThreshold) {
            velocity.y = 0;
            grounded = 1;
            position.y = groundThreshold;
        } else {
            grounded = 0;
        }

        if (isJumping && grounded) {
            velocity.y = -jumpHeight;
        }

        std::cout << groundThreshold - position.y  << "\n";

        // render
        BeginDrawing();
            ClearBackground(BLACK);
            DrawCircle(position.x, position.y, 3, WHITE);
        EndDrawing();
    }

    CloseWindow();
}