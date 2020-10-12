#pragma once
//#include "../Entity.h"

class Entity;
class Collider;

/**
 Baseclass for anything that can be attached to an Entity.
 Attachments can be used to define behaviour, controls or rendering options for an Entity.
*/
class Attachment
{
public:
	/**
	 Constructor for Attachment.
	 Constructs an new Attachment.

	 @param ent The Entity to which this Attachment is attached.
	*/
	Attachment(Entity* ent);

	/**
	 Check if Attachment is active.

	 @return true of Attachment is active, false otherwise
	*/
	bool IsActive();

	/**
	 Activate or deactivate Attachment.

	 @param val Activate if true, deactivate otherwise.
	*/
	void SetActive(bool val);

	/**
	 Get the Entity that this Attachment is attached to.

	 @return The Entity that this Attachment is attached to.
	*/
	Entity* GetEntity();

	/**
	Initialize this Attachment.
	*/
	virtual void Init();

	/**
	Update this Attachment.

	@param deltaTime Time elapsed between the last frame and the current frame.
	*/
	virtual void Update(float deltaTime);

	/**
	 Method to call when the Entity is colliding with another Entity that has a Collider.

	 @param other The other Collider with which the Entity collided.
	*/
	virtual void OnCollision(Collider* other);

private:
	bool activated;
	Entity* entity;
};
