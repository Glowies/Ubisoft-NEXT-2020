#include "stdafx.h"
#include "ColorType.h"
#include <stdlib.h>

ColorType::Color ColorType::RandomColor()
{
	ColorType::Color* colors = new ColorType::Color[3]{ red, blue, green };
	ColorType::Color result = colors[rand() % ColorType::colorCount];
	delete colors;
	return result;
}