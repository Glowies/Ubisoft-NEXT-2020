#pragma once
#include "Renderer.h"

/**
 Renderer used to display the player.
*/
class PlayerRenderer :
	public Renderer
{
public:
	/**
	 Constructor for PlayerRenderer.
	 Constructs an new PlayerRenderer.

	 @param ent The Entity to which this PlayerRenderer is attached.
	*/
	PlayerRenderer(Entity* ent) : Renderer(ent) {};

	virtual void Draw() override;
};

