/*******************************************************************************************
*
*   raylib [shapes] example - Draw basic shapes 2d (rectangle, circle, line...)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/
//
#include <iostream>
//#include <ctime>
//#include "synchapi.h"

#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"

#include "Room.h"
#include "Helpers.h"

//#include <Windows.h>
//#ifdef _MSC_VER
//#define _CRT_SECURE_NO_WARNINGS
//#endif

//#define _CROSSES_

int rot_angle(int angle_in)
{
    int angle_out = 1;
    angle_out = GetTime() * angle_in;
    if (angle_out == angle_in)
    {
        return angle_out;
    }
}
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800; //gameam requirement
    const int screenHeight = 600;
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(screenWidth, screenHeight, "Rooms! - press spacebar to rotato 90 deg");
    //SetWindowMonitor(1);
    

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    //--------------------------------------------------------------------------------------
    Vector2 Origin{ screenWidth/2, screenHeight/2};

    Vector2 A{ 0.00, 0.00 };
    Vector2 B{ 0.00, 200.00 };
    Vector2 C{ 200.00, 200.00 };
    Vector2 D{ 200.00, 0.00 };

    Vector2 center{ screenWidth / 2, screenHeight / 2 };
    Vector2 defSize{ 20,100 }; //20px width, 100px height
    int angle = 0;
    int speed = 0;
    float animation = 30 * sinf(GetTime() / 12);
    char formatted[50];
    Room pokoj;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        
        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);
        /*
        *   
        *   OVERLAY XY LINES
        * 
        */
        DrawLine(0, screenHeight/2, screenWidth, screenHeight/2, BLACK); //Horizontal
        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, BLACK); //
        DrawText(formatted, 50, 50, 20, RED);
        rlPushMatrix(); //Matrix of a SINGLE room!
        rlTranslatef(screenWidth / 2, screenHeight / 2, 0);
        

        sprintf(formatted, "Time: %d", (int)(GetTime() / 60));
        
        /*
            GetTime() aktualny czas co do ms mo¿e "pchaæ" obrót
            GetTime() * angle <= 90
        */

        if (IsKeyPressed(KEY_SPACE))
        {
            while (GetTime())
            {
                angle++;
                _sleep(100); //doesnt work :c
                rlRotatef(angle, 0, 0, 1);
                if (angle == 90)
                {
                    break;
                }
            }
            angle = 0;
        }
        
        
        pokoj.Place();
        rlPopMatrix();
        
        //End of local space, going back to the general 0,0 upper left 
        DrawText("Rooms! test", 20, 20, 20, BLACK);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

