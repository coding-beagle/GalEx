/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "raylib.h"
#include "stdio.h"
#include "math.h"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include "vector2utils.h"
#include "playership.h"


#define SHIPSTART_X 500.0
#define SHIPSTART_Y 700.0

int main ()
{
	float last_click_x, last_click_y;

	float ship_pos_x = SHIPSTART_X;
	float ship_pos_y = 100.0;

	last_click_x = -1.0;
	last_click_y = -1.0;

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
		char char_buff[20];
		Vector2 mouse_pos;
		mouse_pos = GetMousePosition();
		sprintf(char_buff, "Mouse x,y = %lf, %lf", mouse_pos.x, mouse_pos.y);
		DrawText(char_buff, 0,0,20, WHITE);

		double ship_angle = atan2((ship_pos_y - mouse_pos.y), (ship_pos_x - mouse_pos.x)) - 3.141562 / 2;

		if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
			last_click_x = mouse_pos.x;
			last_click_y = mouse_pos.y;
		}

		if(last_click_x > -0.5 && last_click_y > -0.5){
			DrawCircle((int)last_click_x, (int)last_click_y, 5, WHITE);
		}

		Vector2 last_click = (Vector2){(float)last_click_x, (float)last_click_y};

		if(abs(ship_pos_x - last_click.x) > 3 && last_click_x > -0.5) {
			ship_pos_x -= (ship_pos_x - last_click.x) / 100.0;
		}
		if(abs(ship_pos_y - last_click.y) > 3 && last_click_y > -0.5) {
			ship_pos_y -= (ship_pos_x - last_click.y) / 100.0;
		}

		// sprintf(char_buff, "Ship Pos x,y = %f, %f", ship_pos_x, ship_pos_y);
		// DrawText(char_buff, 0,30,20, WHITE);

		DrawShip((Vector2){ship_pos_x, ship_pos_y}, ship_angle);
 
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// cleanup

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
