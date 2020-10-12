#pragma once
#include "Collider.h"

/**
 Collider with circular shape that isn't affected by Entity scale.
*/
class CircleCollider :
	public Collider
{
public:
	/**
	 Constructor for CircleCollider.
	 Constructs an new CircleCollider.

	 @param ent The Entity to which this CircleCollider is attached.
	*/
	CircleCollider(Entity* ent) : Collider(ent) {
		radius = 5;
	};

	/**
	 The radius of the circle that describes the CircleCollider
	*/
	float radius;

	virtual bool CollidesWith(Collider* other) override;
};

