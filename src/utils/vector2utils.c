#include "vector2utils.h"

Vector2 RotateVector2(Vector2 vec, double rotation){
	float new_x = vec.x * cos(rotation) - vec.y * sin(rotation);
	float new_y = vec.x * sin(rotation) + vec.y * cos(rotation);

	return (Vector2){new_x, new_y};
}

double MagnitudeVector2(Vector2 vec){
	return sqrt(vec.x * vec.x + vec.y * vec.y);
}

double GetAngleBetweenVectors(Vector2 vec1, Vector2 vec2){
	double dot_prod = vec1.x * vec2.x + vec1.y * vec2.y;
	return acos((dot_prod) / (MagnitudeVector2(vec1) * MagnitudeVector2(vec2)));
}

Vector2 GetRelativeVector(Vector2 vec1, Vector2 vec2){
	return (Vector2){vec1.x - vec2.x, vec1.y - vec2.y};
}