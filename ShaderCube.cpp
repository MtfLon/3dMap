#include <raylib.h>
#include "InfoPrint.h"
#include "CubeChars.h"
#include "Drawning.h"
#include <vector>
#include <random>
const int screenWidth = 1000;
const int screenHeight = 1000;
int main()
{
    InitWindow(screenWidth, screenHeight, "Cube");
    Camera3D camera = { 0 };
    camera.position = Vector3{ 0.0f, 10.0f, 10.0f };
    camera.target = Vector3{ 0.0f, 0.0f, 0.0f };
    camera.up = Vector3{ 0.0f, 0.1f, 0.0f };
    camera.fovy = 450.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    int cameraMode = CAMERA_FIRST_PERSON;
    for (int i = 0; i < MAX_COLUMNS; i++)
    {
        shapeHeights[i] = static_cast<float>(heightDist(gen));
        shapePosition[i] = Vector3{ static_cast<float>(posDist(gen)), shapeHeights[i] / 2.0f, static_cast<float>(posDist(gen)) };
        shapeColors[i] = Color{ static_cast<unsigned char>(colorDist(gen)),
                                static_cast<unsigned char>(greenDist(gen)),
                                30, 255 };
    }
    DisableCursor();
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ONE)) {
            cameraMode = CAMERA_FREE;
            camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
        }
        if (IsKeyPressed(KEY_TWO))
        {
            cameraMode = CAMERA_FIRST_PERSON;
            camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
        }
        if (IsKeyPressed(KEY_THREE))
        {
            cameraMode = CAMERA_THIRD_PERSON;
            camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
        }
        if (IsKeyPressed(KEY_FOUR))
        {
            cameraMode = CAMERA_ORBITAL;
            camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
        }

        if (IsKeyPressed(KEY_P))
        {
            if (camera.projection == CAMERA_PERSPECTIVE)
            {     
                cameraMode = CAMERA_THIRD_PERSON;
                camera.position = Vector3{ 0.0f, 2.0f, -100.0f };
                camera.target = Vector3{ 0.0f, 2.0f, 0.0f };
                camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
                camera.projection = CAMERA_ORTHOGRAPHIC;
                camera.fovy = 120.0f; 
            }
            else if (camera.projection == CAMERA_ORTHOGRAPHIC)
            {     
                cameraMode = CAMERA_THIRD_PERSON;
                camera.position = Vector3{ 0.0f, 2.0f, 10.0f };
                camera.target = Vector3{ 0.0f, 2.0f, 0.0f };
                camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
                camera.projection = CAMERA_PERSPECTIVE;
                camera.fovy = 160.0f;
            }
        }
        UpdateCamera(&camera, cameraMode);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera);
        DrawMap();
        DrawCubes();  
        PrintInfo(camera, cameraMode);
        EndMode3D();
        PrintInfo(camera, cameraMode);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
///чтобы выгрузить текстуры модели звуки и тд с надо еще приводить путь к файлу к (char*)