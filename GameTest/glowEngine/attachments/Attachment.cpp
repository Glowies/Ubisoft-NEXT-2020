#include "stdafx.h"
#include "Attachment.h"

Attachment::Attachment(Entity* ent)
{
	entity = ent;
	activated = true;
}

bool Attachment::IsActive()
{
	return activated;
}

void Attachment::SetActive(bool val)
{
	activated = val;
}

Entity* Attachment::GetEntity()
{
	return entity;
}

void Attachment::Init()
{
}

void Attachment::Update(float deltaTime)
{
}

void Attachment::OnCollision(Collider* other)
{
}
