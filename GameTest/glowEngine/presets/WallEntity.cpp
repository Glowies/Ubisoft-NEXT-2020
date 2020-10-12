#include "stdafx.h"
#include "WallEntity.h"
#include "../GlowEngine.h"

WallEntity::WallEntity() : Entity()
{
	TunnelTraveler* trav = AddAttachment<TunnelTraveler>();
	WallRenderer* rend = AddAttachment<WallRenderer>();
	AddAttachment<CircleCollider>();
	trav->radius = 1000;
	trav->velocity = -300;
}