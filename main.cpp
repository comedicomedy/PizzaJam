#include <iostream>
#include "raylib.h"
#include "string"
#include "tmx.h"
#define RAYLIB_TMX_IMPLEMENTATION
#include "raylib-tmx.h"


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
        if (IsKeyDown(KEY_S) && pos.y < 1080-35) pos.y += speed;
        if (IsKeyDown(KEY_D) && pos.x < 1920-21) pos.x += speed;
        if (IsKeyDown(KEY_A) && pos.x >= 0) pos.x -= speed;
    }

};



int main(void) {
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    auto _player =  player(10);
    int time = 5;

    InitWindow(screenWidth,screenHeight, "Pizza Jam");
    _player.pos = {screenWidth/2-21/2, screenHeight/2-35/2};

    //Loading Texture
    Texture2D playerSpriteLit = LoadTexture("Sprites/BombBoyV2Lit");
    tmx_map* testLevel = LoadTMX("TestMap.tmx");

    SetTargetFPS(60);
    while (!WindowShouldClose()){
        if (GetTime() <= 5){
            _player.control();
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawTexture(playerSpriteLit, _player.pos.x, _player.pos.y,WHITE);

            DrawText(std::to_string(GetTime()).data(),0,0,40,LIGHTGRAY);
            DrawTMX(testLevel, 0,0,WHITE);
        EndDrawing();
    }

    UnloadTexture(playerSpriteLit);

    CloseWindow();

    return 0;
}