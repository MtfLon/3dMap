#pragma once
#include <raylib.h>
#include "CubeChars.h"
void DrawCubes()
{
    for (int i = 0; i < MAX_COLUMNS; i++)
    {
        DrawCube(shapePosition[i], 2.0f, shapeHeights[i], 2.0f, shapeColors[i]);
        DrawCubeWires(shapePosition[i], 2.0f, shapeHeights[i], 2.0f, MAROON);
    }
}
void DrawMap()
{
    DrawPlane(Vector3{ 0.0f, 0.0f, 0.0f }, Vector2{ 52.0f, 52.0f }, LIGHTGRAY);
    DrawCube(Vector3{ -20.0f, 3.5f, 0.0f }, 1.0f, 5.0f, 40.9f, BLUE);
    DrawCube(Vector3{ 20.0f, 3.5f, 0.0f }, 1.0f, 5.0f, 40.9f, LIME);
    DrawCube(Vector3{ 0.0f, 3.5f, 20.0f }, 40.9f, 5.0f, 1.0f, GOLD);
}