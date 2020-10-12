#pragma once
#include "Renderer.h"

/**
 Renderer that is used to display enemy ships.
*/
class EnemyRenderer :
	public Renderer
{
public:
	/**
	 Constructor for EnemyRenderer.
	 Constructs an new EnemyRenderer.

	 @param ent The Entity to which this EnemyRenderer is attached.
	*/
	EnemyRenderer(Entity* ent) : Renderer(ent) {};

	virtual void Draw() override;
};

