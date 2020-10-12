#include "stdafx.h"
#include "ColorableTraveler.h"
#include "../../GlowEngine.h"

void ColorableTraveler::Update(float deltaTime) {
	Renderer* rend = GetEntity()->GetAttachment<Renderer>();
	switch (colorType) {
	case ColorType::Color::red:
		rend->r = 1;
		rend->g = .3f;
		rend->b = .3f;
		break;
	case ColorType::Color::green:
		rend->r = .3f;
		rend->g = 1;
		rend->b = .3f;
		break;
	case ColorType::Color::blue:
		rend->r = .5f;
		rend->g = .5f;
		rend->b = 1;
		break;
	default:
		rend->r = 1;
		rend->g = 1;
		rend->b = 1;
	}
}