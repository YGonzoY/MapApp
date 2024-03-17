
#include "raylib.h"


int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);

    #define PeaceSize 40 


    InitWindow(screenWidth, screenHeight, "app");

    RenderTexture2D target = LoadRenderTexture(screenWidth, screenHeight);

    // Clear render texture before entering the game loop
    BeginTextureMode(target);
    ClearBackground(RAYWHITE);;
    EndTextureMode();

    SetTargetFPS(120);

    while (!WindowShouldClose())
    {
        Vector2 mousePos = GetMousePosition();
        BeginDrawing();

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) || (GetGestureDetected() == GESTURE_DRAG))
        {
            BeginTextureMode(target);
            DrawRectangle((int)mousePos.x - (int)mousePos.x%PeaceSize, (int)mousePos.y - (int)mousePos.y%PeaceSize, PeaceSize, PeaceSize, BLACK);
            //DrawCircle((int)mousePos.x, (int)mousePos.y, 10, BLACK);
            EndTextureMode();
        }

        ClearBackground(RAYWHITE);
        DrawTextureRec(target.texture, (Rectangle) { 0, 0, (float)target.texture.width, (float)-target.texture.height }, (Vector2) { 0, 0 }, WHITE);

        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}