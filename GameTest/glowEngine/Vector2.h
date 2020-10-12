#pragma once

/**
 2 Dimensional vector class.
*/
class Vector2
{
public:
	/**
	 Constructor for Vector2.
	 Instantiates a Vector2 with values (0, 0).
	*/
	Vector2();

	/**
	 Constructor for Vector2.

	 @param iX The initial x value of the Vector.
	 @param iY The initial y value of the Vector.
	*/
	Vector2(float iX, float iY);

	/**
	 Values of the vector.
	*/
	float x, y;

	/**
	 Calculate the distance between two vectors

	 @param v1 First vector
	 @param v2 Second vector
	*/
	static float Distance(Vector2 v1, Vector2 v2);

	static const Vector2 zero, up, down, left, right, one;
};

