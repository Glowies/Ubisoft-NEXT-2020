#include "stdafx.h"
#include "TextRenderer.h"
#include "../../../App/app.h"

void TextRenderer::Draw()
{
	App::Print(position.x, position.y, text, r, g, b);
}