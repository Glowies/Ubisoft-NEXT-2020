#pragma once

class ColorType
{
public:
	static const int colorCount = 3;
	enum Color {red, green, blue, white};
	static Color RandomColor();
};

