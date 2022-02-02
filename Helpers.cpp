#include <iostream>

#include "raylib.h"
#include "rlgl.h"


void SetPivotMatrix(Vector2 pos, Vector2 pivot, float angle)
{
    rlTranslatef(pos.x, pos.y, 0);
    rlRotatef(angle, 0, 0, 1);
    rlTranslatef(-pivot.x, -pivot.y, 0);
}

void DrawCross(char* params)
{
    DrawLineEx(Vector2{ -20, 0 }, Vector2{ 20, 0 }, 2, RED);
    DrawLineEx(Vector2{ 0, -20 }, Vector2{ 0, 20 }, 2, RED);
    DrawCircleLines(0, 0, 10, RED);
    DrawText(params, 30, 30, 10, BLUE); //Display location
}

void PutBlock(float X, float Y, float Rot, Color Kolor)
{
    char params[50];
    int loc_width, loc_height;
    loc_width = 30;
    loc_height = 100;
    std::sprintf(params, "X: %.3f\nY: %.3f", X, Y);
    rlPushMatrix();
    rlTranslatef(X, Y, 0); //Move all that crap beneath
    rlPushMatrix();
    rlRotatef(Rot, 0, 0, 1);
    rlTranslatef(-loc_width / 2, -loc_height / 2, 0); //Moving its matrix by half, to acquire center of the single cell
    DrawRectangle(0, 0, loc_width, loc_height, Kolor);
#ifdef __CROSSES__
    DrawRectangleLines(0, 0, loc_width, loc_height, GREEN);
#endif 
    rlPopMatrix();
#ifdef __CROSSES__
    DrawLineEx(Vector2{ -20, 0 }, Vector2{ 20, 0 }, 2, RED);
    DrawLineEx(Vector2{ 0, -20 }, Vector2{ 0, 20 }, 2, RED);
    DrawCircleLines(0, 0, 10, RED);
    DrawText(params, 30, 30, 10, BLUE); //Display location
#endif
    rlPopMatrix();
}

void PutCorner(float X, float Y, Color Kolor)
{
    char params[50];
    int loc_width, loc_height;
    loc_width = 30;
    loc_height = 30;
#ifdef __CROSSES__
    sprintf(params, "X: %.3f\nY: %.3f", X, Y);
#endif
    rlPushMatrix();
    rlTranslatef(X, Y, 0); //Move all that crap beneath
    rlPushMatrix();
    //rlRotatef(Rot, 0, 0, 1);
    rlTranslatef(-loc_width / 2, -loc_height / 2, 0); //Moving its matrix by half, to acquire center of the single cell
    DrawRectangle(0, 0, loc_width, loc_height, Kolor);
#ifdef __CROSSES__
    DrawRectangleLines(0, 0, loc_width, loc_height, GREEN);
#endif 
    rlPopMatrix();
#ifdef __CROSSES__
    DrawCross(params);
#endif
    rlPopMatrix();
}

void TestRoom()
{
    float cornersize = 30;
    Vector2 position = { 0,0 };
    char buffer[50]; //for debug purposes
    sprintf(buffer, "%.3f\n%.3f", position.x, position.y);
    DrawCross(buffer);
    rlPushMatrix();
    //New temporary local 
    //Animation :)
    /*rlScalef(sinf(GetTime() / 12 * 15), sin(GetTime() / 12 * 15), 0);
    rlRotatef(30 * sinf(GetTime()/12 * 45), 0, 0, 1);*/

    /*
    *   LEFT WALL
    */
    PutBlock(-150, -100, 0, BLACK);
    //PutBlock(-150, 0, 0, BLACK);
    PutBlock(-150, 100, 0, BLACK);

    /*
    *   RIGHT WALL
    */
    PutBlock(150, -100, 0, BLACK);
    PutBlock(150, 0, 0, BLACK);
    PutBlock(150, 100, 0, BLACK);
    /*
    *   TOP WALL
    */
    PutBlock(100, 150, 90, BLACK);
    PutBlock(0, 150, 90, BLACK);
    PutBlock(-100, 150, 90, BLACK);
    /*
    *   BOTTOM WALL
    */
    PutBlock(100, -150, 90, BLACK);
    //PutBlock(0, -150, 90, BLACK);
    PutBlock(-100, -150, 90, BLACK);

    //Left Upper Corner
    PutCorner(-150, 150, BLACK);
    //Left Lower Corner
    PutCorner(-150, -150, BLACK);
    //Right Upper Corner
    PutCorner(150, 150, BLACK);
    //Right Lower Corner
    PutCorner(150, -150, BLACK);

    rlPopMatrix();
}