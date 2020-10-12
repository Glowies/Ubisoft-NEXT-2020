#include "stdafx.h"
#include "PlayerEntity.h"

PlayerEntity::PlayerEntity() : Entity()
{
	TunnelTraveler* trav = AddAttachment<PlayerTraveler>();
	AddAttachment<PlayerRenderer>();
	AddAttachment<CircleCollider>();
	GetAttachment<Transform>()->position = Vector2(512, 200);
	GetAttachment<Transform>()->scale = Vector2(3, 1);
}
