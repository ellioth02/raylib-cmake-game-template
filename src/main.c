#include <raylib.h>

int main()
{
    const int WIDTH = 600;
    const int HEIGHT = 400;
    const char* title = "Raylib CMake Game Template";

    InitWindow(WIDTH, HEIGHT, title);
    SetTargetFPS(60);

    Texture2D logo = LoadTexture(ASSETS_PATH "logo.png");
    const int logo_x = WIDTH / 2 - logo.width / 2;
    const int logo_y = HEIGHT / 2 - logo.height / 2 - 60;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText(title, 160, 225, 20, LIGHTGRAY);
        DrawTexture(logo, logo_x, logo_y, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
