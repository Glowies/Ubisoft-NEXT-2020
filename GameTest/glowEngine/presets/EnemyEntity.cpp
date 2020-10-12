#include "stdafx.h"
#include "EnemyEntity.h"

EnemyEntity::EnemyEntity() : Entity()
{
	EnemyTraveler* trav = AddAttachment<EnemyTraveler>();
	EnemyRenderer* rend = AddAttachment<EnemyRenderer>();
	AddAttachment<CircleCollider>();
	trav->radius = 1000;
	trav->velocity = -100;
}