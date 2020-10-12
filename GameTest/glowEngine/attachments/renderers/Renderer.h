#pragma once
#include "../Attachment.h"

/**
 Abstract Renderer class.
 Declares the signature of the Draw method which will draw onto the screen according to subclass implementations.
*/
class Renderer : public Attachment
{
public:
	/**
	 Constructor for Renderer.
	 Constructs an new Renderer.

	 @param ent The Entity to which this Renderer is attached.
	*/
	Renderer(Entity* ent) : Attachment(ent) {
		r = 1;
		g = 1;
		b = 1;
	};

	/**
	 Floats defining the color of the drawing
	*/
	float r, g, b;

	/**
	 Draw to screen according to the specifications of this Renderer.
	*/
	virtual void Draw() = 0;

	virtual void Init() override;

	virtual void Update(float deltaTime) override;
};

