#pragma once
#include "Renderer.h"
#include "../../Vector2.h"

/**
 Renderer used to display text on to the screen.
*/
class TextRenderer :
	public Renderer
{
public:
	/**
	 Constructor for TextRenderer.
	 Constructs an new TextRenderer.

	 @param ent The Entity to which this TextRenderer is attached.
	*/
	TextRenderer(Entity* ent) : Renderer(ent) {
		sprintf(text, "P L A C E H O L D E R");
		position = Vector2::zero;
	};

	/**
	 The text that will be displayed by the renderer.
	 Max 63 characters.
	*/
	char text[64];

	/**
	 The position where the text will be displayed.
	*/
	Vector2 position;

	void Draw() override;
};

