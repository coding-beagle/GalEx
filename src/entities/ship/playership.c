#include "playership.h"

void DrawShip(Vector2 screen_pos, double rotation){
	Vector2 v1, v2, v3;

	v1.x = - 6;
	v1.y = 0;

	v1 = RotateVector2(v1, rotation);

	v1.x += screen_pos.x;
	v1.y += screen_pos.y;

	v2.x = 0;
	v2.y = -20;

	v2 = RotateVector2(v2, rotation);

	v2.x += screen_pos.x;
	v2.y += screen_pos.y;

	v3.x = 6;
	v3.y = 0;

	v3 = RotateVector2(v3, rotation);

	v3.x += screen_pos.x;
	v3.y += screen_pos.y;

	DrawTriangleLines(v1, v2, v3, WHITE);
}
