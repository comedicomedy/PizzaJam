#include <iostream>
#include "raylib.h"

class player{
    public:
        Vector2 pos;
        Rectangle hitBox = {pos.x, pos.y, 35, 35};
        float speed;

        player(float pSpeed){
            speed = pSpeed;
        }
    ;

    void control(){
        if (IsKeyDown(KEY_W) && pos.y >= 0) pos.y -= speed;
        if (IsKeyDown(KEY_S) && pos.y <= 600) pos.y += speed;
        if (IsKeyDown(KEY_D) && pos.x <= 800) pos.x += speed;
        if (IsKeyDown(KEY_A) && pos.x >= 0) pos.x -= speed;
    }
};

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 600;
    auto _player =  player(2.5);

    InitWindow(screenWidth,screenHeight, "Pizza Jam");
    _player.pos = {screenWidth/2 -35/2, screenHeight/2 -35/2};

    while (!WindowShouldClose()){
        _player.control();

        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawRectangle(_player.pos.x, _player.pos.y, 35, 35, RED);
        EndDrawing();
    }

    return 0;
}
