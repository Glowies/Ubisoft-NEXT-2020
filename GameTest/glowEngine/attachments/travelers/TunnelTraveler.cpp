#include "stdafx.h"
#include "TunnelTraveler.h"
#include "../../GlowEngine.h"

void TunnelTraveler::TunnelUpdate(float deltaTime, Tunnel* refTunnel)
{
	int trackCount = refTunnel->trackCount;
	Vector2 center = refTunnel->GetEntity()->GetAttachment<Transform>()->position;
	float tunnelRotation = refTunnel->GetEntity()->GetAttachment<Transform>()->rotation;

	radius += deltaTime * velocity / 1000;

	Transform* transform = GetEntity()->GetAttachment<Transform>();

	const float pi = 3.14159f;
	const float angleStep = 2 * pi / trackCount;

	const float x = center.x + radius * cosf(tunnelRotation + angleStep * track + angleStep / 2);
	const float y = center.y + radius * sinf(tunnelRotation + angleStep * track + angleStep / 2);

	transform->position = Vector2(x, y);
	transform->rotation = tunnelRotation + angleStep * track + angleStep / 2;
	transform->scale.x = 2 * radius * tanf(angleStep / 2);
	transform->scale.y = 2 * radius * tanf(angleStep / 2);
}

void TunnelTraveler::Init()
{
}

void TunnelTraveler::Update(float deltaTime)
{
}
