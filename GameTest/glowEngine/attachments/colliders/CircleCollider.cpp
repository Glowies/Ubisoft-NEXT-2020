#include "stdafx.h"
#include "CircleCollider.h"
#include "../../GlowEngine.h"

bool CircleCollider::CollidesWith(Collider* other)
{
	if (dynamic_cast<CircleCollider*>(other) != NULL) {
		Vector2 pos1 = GetEntity()->GetAttachment<Transform>()->position;
		Vector2 pos2 = other->GetEntity()->GetAttachment<Transform>()->position;
		float distance = Vector2::Distance(pos1, pos2);

		if (distance < radius + ((CircleCollider*)other)->radius)
			return true;
	}

	return false;
}
