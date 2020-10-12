#pragma once
#include "Renderer.h"

/**
 Renderer for the wall obstacles.
*/
class WallRenderer :
	public Renderer
{
public:
	/**
	 Constructor for WallRenderer.
	 Constructs an new WallRenderer.

	 @param ent The Entity to which this WallRenderer is attached.
	*/
	WallRenderer(Entity* ent) : Renderer(ent) {};

	virtual void Draw() override;
};

