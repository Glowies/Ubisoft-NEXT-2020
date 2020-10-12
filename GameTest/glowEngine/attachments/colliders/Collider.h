#pragma once
#include "../Attachment.h"

/**
 The Collider Attachment is used to check collisions with other entites that have Colliders.
*/
class Collider :
	public Attachment
{
public:
	/**
	 Constructor for Collider.
	 Constructs an new Collider.

	 @param ent The Entity to which this Collider is attached.
	*/
	Collider(Entity* ent) : Attachment(ent) {};


	/**
	 Collision check with another Collider.

	 @param other The other Collider to check collision with.
	*/
	virtual bool CollidesWith(Collider* other) = 0;
};

