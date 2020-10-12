#include "stdafx.h"
#include "Vector2.h"



Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float iX, float iY) {
	x = iX;
	y = iY;
}

float Vector2::Distance(Vector2 v1, Vector2 v2)
{
	return sqrtf((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
}

const Vector2 Vector2::zero(0, 0);
const Vector2 Vector2::up(0, 1);
const Vector2 Vector2::down(0, -1);
const Vector2 Vector2::left(-1, 0);
const Vector2 Vector2::right(1, 0);
const Vector2 Vector2::one(1, 1);