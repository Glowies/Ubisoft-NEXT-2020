#include "stdafx.h"
#include "TunnelRenderer.h"
#include "../../../App/app.h"
#include "../../Vector2.h"
#include "../../Entity.h"
#include "../Transform.h"

void TunnelRenderer::Draw() {
	int trackCount = tunnel->trackCount;
	float innerRadius = tunnel->innerRadius;
	float outerRadius = tunnel->outerRadius;

	Vector2 pos = GetEntity()->GetAttachment<Transform>()->position;
	float rotation = GetEntity()->GetAttachment<Transform>()->rotation;

	const float pi = 3.14159f;
	const float angleStep = 2 * pi / trackCount;
	// Draw Main Structure
	for (int i = 0; i < trackCount; i++) {
		float x1, y1, x2, y2, x3, y3;
		x1 = pos.x + innerRadius * cosf(rotation + angleStep * i);
		y1 = pos.y + innerRadius * sinf(rotation + angleStep * i);
		x2 = pos.x + innerRadius * cosf(rotation + angleStep * (i + 1));
		y2 = pos.y + innerRadius * sinf(rotation + angleStep * (i + 1));
		x3 = pos.x + outerRadius * cosf(rotation + angleStep * i);
		y3 = pos.y + outerRadius * sinf(rotation + angleStep * i);

		App::DrawLine(x1, y1, x2, y2, r, g, b);
		App::DrawLine(x1, y1, x3, y3, r, g, b);
	}

	// Draw inner decoration
	const float angleDelta = 15;
	for (float j = innerRadius; j > 0; j -= 0.5f) {
		for (int i = 0; i < trackCount; i++) {
			float x1, y1, x2, y2;
			x1 = pos.x + j * cosf(rotation + angleStep * i );
			y1 = pos.y + j * sinf(rotation + angleStep * i);
			x2 = pos.x + j * cosf(rotation + angleStep * (i + 1));
			y2 = pos.y + j * sinf(rotation + angleStep * (i + 1));

			App::DrawLine(x1, y1, x2, y2, r, g, b);
		}
	}
}

void TunnelRenderer::Init()
{
	tunnel = GetEntity()->GetAttachment<Tunnel>();
}
