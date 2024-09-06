#pragma once
#include <vector>
#include <random>
#include<raylib.h>
const int MAX_COLUMNS = 20;
std::vector<float> shapeHeights(MAX_COLUMNS);
std::vector<Vector3> shapePosition(MAX_COLUMNS);
std::vector<Color> shapeColors(MAX_COLUMNS);

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> heightDist(1, 12);
std::uniform_int_distribution<> posDist(-15, 15);
std::uniform_int_distribution<> colorDist(20, 255);
std::uniform_int_distribution<> greenDist(10, 55);