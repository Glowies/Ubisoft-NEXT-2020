#pragma once
#include "Renderer.h"

/**
 Class used to render regular polygons.
*/
class RegularPolygonRenderer : public Renderer
{
public:
	/**
	 Constructor for RegularPolygonRenderer.
	 Constructs an new RegularPolygonRenderer.

	 @param ent The Entity to which this RegularPolygonRenderer is attached.
	*/
	RegularPolygonRenderer(Entity* ent) : Renderer(ent) {
		radius = 0.5f;
		vertexCount = 3;
	};

	/**
	 The polygon's radius
	*/
	float radius;

	/**
	 The polygon's number of vertices
	*/
	float vertexCount;

	void Draw() override;
};

