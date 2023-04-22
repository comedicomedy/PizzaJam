#include <iostream>
#include "raylib.h"
#include "string"

class player{
    public:
        Vector2 pos;
        Rectangle hitBox = {pos.x, pos.y, 21, 35};
        float speed;

        player(float pSpeed){
            speed = pSpeed;
        }
        ;

    void control(){
        if (IsKeyDown(KEY_W) && pos.y >= 0) pos.y -= speed;
        if (IsKeyDown(KEY_S) && pos.y < 600-35) pos.y += speed;
        if (IsKeyDown(KEY_D) && pos.x < 800-21) pos.x += speed;
        if (IsKeyDown(KEY_A) && pos.x >= 0) pos.x -= speed;
    }

};

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 600;
    auto _player =  player(2.5);
    int time = 5;

    InitWindow(screenWidth,screenHeight, "Pizza Jam");
    _player.pos = {screenWidth/2-21/2, screenHeight/2-35/2};

    //Loading Texture
    Texture2D playerSprite = LoadTexture("Sprites/BombBoy.png");

    SetTargetFPS(60);
    while (!WindowShouldClose()){
        if (GetTime() <= 5){
            _player.control();
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawTexture(playerSprite, _player.pos.x, _player.pos.y,WHITE);

            DrawText(std::to_string(GetTime()).data(),0,0,40,LIGHTGRAY);
        EndDrawing();
    }

    UnloadTexture(playerSprite);

    CloseWindow();

    return 0;
}
