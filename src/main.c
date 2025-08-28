/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "raylib.h"
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

#include "vector2utils.h"
#include "playership.h"
#include "custom_types.h"


#define SHIPSTART_X 500.0
#define SHIPSTART_Y 500.0

int main ()
{
	float last_click_x = -1.0f, last_click_y = -1.0f;

	float ship_pos_x = SHIPSTART_X, ship_pos_y = SHIPSTART_Y;
	double ship_rotation = 0.0;

	Ship_T char_ship;

	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(1280, 800, "Hello Raylib");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");
	
	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		// drawing
		BeginDrawing();

		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);

		// draw some text using the default font

		Vector2 mouse_pos = GetMousePosition();

		// char char_buff[20];
		// sprintf(char_buff, "Mouse x,y = %lf, %lf", mouse_pos.x, mouse_pos.y);
		// DrawText(char_buff, 0,0,20, WHITE);


		if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
			last_click_x = mouse_pos.x;
			last_click_y = mouse_pos.y;
			ship_rotation = atan2((ship_pos_y - last_click_y), (ship_pos_x - last_click_x)) - 3.141562 / 2;
		}

		// if(last_click_x > -0.5 && last_click_y > -0.5){
		// 	DrawCircle((int)last_click_x, (int)last_click_y, 2, WHITE);
		// }

		if(fabs(ship_pos_x - last_click_x) > 2.0 && last_click_x > -0.5) {
    		ship_pos_x -= 0.01f * (ship_pos_x - last_click_x);
		}
		if(fabs(ship_pos_y - last_click_y) > 2.0 && last_click_x > -0.5) {
		    ship_pos_y -= 0.01f * (ship_pos_y  - last_click_y);
		}
		if(fabs(ship_pos_x - last_click_x) < 2.0 && fabs(ship_pos_y - last_click_y) < 2.0){
			last_click_x = -0.5;
			last_click_y = -0.5;
		}

		char_ship.ShipPos = (Vector2){ship_pos_x, ship_pos_y};
		char_ship.ShipRotation = ship_rotation;

		DrawShip(&char_ship);
 
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// cleanup

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
