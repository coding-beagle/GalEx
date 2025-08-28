#include "playership.h"

void DrawShip(Ship_T* ship_inst){
	Vector2 v1, v2, v3;

	v1.x = - 6;
	v1.y = 0;

	v1 = RotateVector2(v1, ship_inst->ShipRotation);

	v1.x += ship_inst->ShipPos.x;
	v1.y += ship_inst->ShipPos.y;

	v2.x = 0;
	v2.y = -20;

	v2 = RotateVector2(v2, ship_inst->ShipRotation);

	v2.x += ship_inst->ShipPos.x;
	v2.y += ship_inst->ShipPos.y;

	v3.x = 6;
	v3.y = 0;

	v3 = RotateVector2(v3, ship_inst->ShipRotation);

	v3.x += ship_inst->ShipPos.x;
	v3.y += ship_inst->ShipPos.y;

	DrawTriangleLines(v1, v2, v3, WHITE);
}
