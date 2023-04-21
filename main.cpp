#include <iostream>
#include "raylib.h"

class player{
    public:
        Vector2 pos;
        Rectangle hitBox = {pos.x, pos.y, 10, 10};
        float speed;

        player(float _speed){
            _speed = speed;
        }
    ;

    void control(){
        if (IsKeyDown(KEY_W) && pos.y > 0) pos.y -= speed;
        if (IsKeyDown(KEY_S) && pos.y < 600) pos.y += speed;
        if (IsKeyDown(KEY_D) && pos.x < 800) pos.x += speed;
        if (IsKeyDown(KEY_A) && pos.x > 0) pos.x -= speed;
    }
};

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 600;
    player Player =  player(2.5);

    InitWindow(screenWidth,screenHeight, "Pizza Jam");

    while (!WindowShouldClose()){

        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawRectangle(Player.pos.x, Player.pos.y, 10, 10, RED);
        EndDrawing();
    }

    return 0;
}
