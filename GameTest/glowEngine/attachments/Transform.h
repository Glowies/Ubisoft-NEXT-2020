#pragma once
#include "Attachment.h"
#include "../Vector2.h"

class Transform : public Attachment
{
public:
	/**
	 Constructor for Transform.
	 Constructs an new Transform.

	 @param ent The Entity to which this Transform is attached.
	*/
	Transform(Entity* ent) : Attachment(ent) {
		position = Vector2::zero;
		scale = Vector2::one;
		rotation = 0;
	};

	/**
	 Position of the Entity that the Transform is attached to.
	*/
	Vector2 position;

	/**
	 Local scale factor of the Entity that the Transform is attached to.
	*/
	Vector2 scale;

	/**
	 Rotation of the Entity that the Transform is attached to.
	*/
	float rotation;

	virtual void Init() override;

	virtual void Update(float deltaTime) override;
};
