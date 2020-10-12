#include "stdafx.h"
#include "RegularPolygonRenderer.h"
#include "../../../App/app.h"
#include "../../Vector2.h"
#include "../../Entity.h"
#include "../Transform.h"

void RegularPolygonRenderer::Draw() {
	Vector2 pos = GetEntity()->GetAttachment<Transform>()->position;
	Vector2 scale = GetEntity()->GetAttachment<Transform>()->scale;
	float rotation = GetEntity()->GetAttachment<Transform>()->rotation;

	const float pi = 3.14159f;
	const float angleStep = 2 * pi / vertexCount;
	for (int i = 0; i < vertexCount; i++) {
		Vector2 p1_offset = Vector2(radius * cosf(angleStep * i) * scale.x, radius * sinf(angleStep * i) * scale.y);
		Vector2 p2_offset = Vector2(radius * cosf(angleStep * (i+1)) * scale.x, radius * sinf(angleStep * (i+1)) * scale.y);


		Vector2 p1_rotated(p1_offset.x * cosf(rotation) - p1_offset.y * sinf(rotation), p1_offset.x * sinf(rotation) + p1_offset.y * cosf(rotation));
		Vector2 p2_rotated(p2_offset.x * cosf(rotation) - p2_offset.y * sinf(rotation), p2_offset.x * sinf(rotation) + p2_offset.y * cosf(rotation));

		float x1, y1, x2, y2;
		x1 = pos.x + p1_rotated.x;
		y1 = pos.y + p1_rotated.y;
		x2 = pos.x + p2_rotated.x;
		y2 = pos.y + p2_rotated.y;
		
		App::DrawLine(x1, y1, x2, y2, r, g, b);
	}
}