/*
* 
* Rooms! - a tiny logic game with rotating rooms
* 
*/
#include <iostream>

#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"

#include "Room.h"
#include "Helpers.h"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

// Adds lines and actual position to an object
//#define _CROSSES_ 

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT | FLAG_WINDOW_HIGHDPI);
    InitWindow(screenWidth, screenHeight, "Rooms!");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    //--------------------------------------------------------------------------------------

    Vector2 center{ screenWidth / 2, screenHeight / 2 };

    int angle = 0;
    int speed = 0;
    float animation = 30 * sinf(GetTime() / 12);
    char formatted[50];
    cRoom Room;
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
        
        DrawText(formatted, 50, 50, 20, RED);
        rlPushMatrix(); //Matrix of a SINGLE room!
        rlTranslatef(screenWidth / 2, screenHeight / 2, 0);
        sprintf(formatted, "Time: %d", (int)(GetTime() / 60));
        if (IsKeyPressed(KEY_SPACE))
        {
            angle += 90;

        }
        Room.Place();
        rlPopMatrix();
        //End of local space, going back to the general 0,0 upper left 
        DrawText("Rooms! - hit space", 20, 20, 20, BLACK);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

