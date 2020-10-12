#include "stdafx.h"
#include "EnemyRenderer.h"
#include "../../GlowEngine.h"

void EnemyRenderer::Draw()
{
	Vector2 pos = GetEntity()->GetAttachment<Transform>()->position;
	Vector2 scale = GetEntity()->GetAttachment<Transform>()->scale;
	float rotation = GetEntity()->GetAttachment<Transform>()->rotation;
	float refScale = 0.45f;

	int vertexCount = 6;
	Vector2* point = new Vector2[vertexCount];
	point[0] = Vector2(0, refScale);
	point[1] = Vector2(-3 * refScale / 2, refScale / 3);
	point[2] = Vector2(-refScale / 2, refScale / 3);
	point[3] = Vector2(-refScale / 2, -refScale / 3);
	point[4] = Vector2(-3 * refScale / 2, -refScale / 3);
	point[5] = Vector2(0, -refScale);

	// Scale and rotate each vertex
	for (int i = 0; i < vertexCount; i++) {
		point[i].x *= scale.x / 2;
		point[i].y *= scale.y;

		point[i] = Vector2(point[i].x * cosf(rotation) - point[i].y * sinf(rotation), point[i].x * sinf(rotation) + point[i].y * cosf(rotation));
	}

	// Draw lines connecting the dots
	for (int i = 0; i < vertexCount; i++) {
		float x1, y1, x2, y2;
		x1 = pos.x + point[i % vertexCount].x;
		y1 = pos.y + point[i % vertexCount].y;
		x2 = pos.x + point[(i + 1) % vertexCount].x;
		y2 = pos.y + point[(i + 1) % vertexCount].y;

		App::DrawLine(x1, y1, x2, y2, r, g, b);
	}

	delete point;
}