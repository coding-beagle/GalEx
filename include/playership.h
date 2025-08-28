#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include "vector2utils.h"
#include "raylib.h"

typedef struct Ship_T {
    Vector2 ShipPos;
    double ShipRotation;
} Ship_T;

// draw a triangle centered at screen_pos with rotation rotation in rads
void DrawShip(Ship_T* ship_inst);

void HandleShipUpdate(Ship_T* ship_inst);

#endif