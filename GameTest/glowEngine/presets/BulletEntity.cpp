#include "stdafx.h"
#include "BulletEntity.h"

BulletEntity::BulletEntity() : Entity()
{
	BulletTraveler* trav = AddAttachment<BulletTraveler>();
	RegularPolygonRenderer* rend = AddAttachment<RegularPolygonRenderer>();
	rend->vertexCount = 32;
	rend->radius = .125f;
	AddAttachment<CircleCollider>();
	trav->radius = 1000;
	trav->velocity = -500;
}
