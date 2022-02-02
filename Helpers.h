#pragma once
#include "raylib.h"

void SetPivotMatrix(Vector2 pos, Vector2 pivot, float angle);

void DrawCross(char* params);

void PutBlock(float X, float Y, float Rot, Color Kolor);

void PutCorner(float X, float Y, Color Kolor);

void TestRoom();