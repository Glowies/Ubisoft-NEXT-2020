#pragma once
#include "../../../App/app.h"
#include "Renderer.h"

/**
 Renderer that draws a line.
 The LineRenderer draws a line according to its list of points.
*/
class LineRenderer :
	public Renderer
{
public:
	/**
	 Constructor for LineRenderer.
	 Constructs an new LineRenderer.

	 @param ent The Entity to which this LineRenderer is attached.
	*/
	LineRenderer(Entity* ent) : Renderer(ent) {};

	void Draw() override;
};

