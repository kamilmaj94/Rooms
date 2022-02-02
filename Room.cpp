#include <iostream>
#include "raylib.h"
#include "rlgl.h"

#include "Room.h"
#include "Helpers.h"

cRoom::cRoom() : Scale(1), 
                fCornersize(30),
                vPosition({0,0}),
                vDoors{ { 0, 150 }, //NORTH
                      { -150, 0 }, //WEST
                      { 150, 0 }, //EAST
                      { 0, -150 } } //SOUTH
                
{

}

cRoom::~cRoom()
{
}

void cRoom::Place()
{
#ifdef __CROSSES__
    sprintf(buffer, "%.3f\n%.3f", position.x, position.y);
    DrawCross(buffer);
#endif
    
    rlPushMatrix();

    /*
    *   LEFT WALL
    */
    PutBlock(-150, -100, 0, BLACK);
    PutBlock(-150, 0, 0, BLACK); //WEST
    PutBlock(-150, 100, 0, BLACK);

    /*
    *   RIGHT WALL
    */
    PutBlock(150, -100, 0, BLACK);
    //PutBlock(doors[2].x, doors[2].y, 0, BLACK); //EAST
    PutBlock(150, 100, 0, BLACK);

    /*
    *   TOP WALL
    */
    PutBlock(100, 150, 90, BLACK);
    //PutBlock(doors[0].x, 90, BLACK); //NORTH
    PutBlock(-100, 150, 90, BLACK);

    /*
    *   BOTTOM WALL
    */
    PutBlock(100, -150, 90, BLACK);
    //PutBlock(0, -150, 90, BLACK); //SOUTH
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

void cRoom::Rotate()
{
    /*
    * Placeholder for animated method
    */
    if (IsKeyPressed(KEY_SPACE))
    {
        for (int i = 0; i < 90; i++)
        {
            rlRotatef(1, 0, 0, 1);
        }
    }
}

void cRoom::PutBlock(float X, float Y, float Rot, Color Kolor)
{
    char params[50];
    int loc_width, loc_height;
    loc_width = 30;
    loc_height = 100;
    sprintf(params, "X: %.3f\nY: %.3f", X, Y);
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

void cRoom::PutCorner(float X, float Y, Color Kolor)
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
