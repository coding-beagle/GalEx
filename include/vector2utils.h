#ifndef VECTOR2UTILS_H
#define VECTOR2UTILS_H

#include "raylib.h"
#include "math.h"

// Apply a 2D rotation matrix with angle rotation (in rad) to vec
Vector2 RotateVector2(Vector2 vec, double rotation);

// Find the angle (in rad) between two vectors
double GetAngleBetweenVectors(Vector2 vec1, Vector2 vec2);

// Get the magnitude of a vector2
double MagnitudeVector2(Vector2 vec);

// return vec1 - vec2
Vector2 GetRelativeVector(Vector2 vec1, Vector2 vec2);

#endif