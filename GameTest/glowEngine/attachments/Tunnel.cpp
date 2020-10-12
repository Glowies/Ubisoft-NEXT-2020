#include "stdafx.h"
#include "Tunnel.h"
#include "../GlowEngine.h"

Tunnel::Tunnel(Entity* ent) : Attachment(ent) {
	innerRadius = 48;
	outerRadius = 2048;
	trackCount = 6;
	spinSpeed = 0;
	travelers = new LinkedList<TunnelTraveler>();
	GetEntity()->GetAttachment<Transform>()->rotation = 3;
}

Tunnel::~Tunnel()
{
	LinkedListIterator<TunnelTraveler>* iter = travelers->Iterator();
	while (iter->HasNext()) {
		TunnelTraveler* traveler = iter->Next();
		delete traveler;
	}

	delete iter;
	delete travelers;
}

void Tunnel::AddTraveler(TunnelTraveler* traveler)
{
	travelers->Add(traveler);
}

void Tunnel::RemoveTraveler(TunnelTraveler* traveler)
{
	travelers->Remove(traveler);
}

void Tunnel::ClearTunnel()
{
	LinkedListIterator<TunnelTraveler>* iter = travelers->Iterator();
	while (iter->HasNext()) {
		TunnelTraveler* traveler = iter->Next();
		Level::DestroyEntity(traveler->GetEntity());
	}

	delete iter;
}

void Tunnel::Init()
{
	LinkedListIterator<TunnelTraveler>* iter = travelers->Iterator();
	while (iter->HasNext()) {
		TunnelTraveler* traveler = iter->Next();
		traveler->Init();
	}

	delete iter;
}

void Tunnel::Update(float deltaTime)
{
	// Rotate tunnel according to its spinSpeed
	float newRotation = GetEntity()->GetAttachment<Transform>()->rotation + spinSpeed * deltaTime / 1000;
	GetEntity()->GetAttachment<Transform>()->rotation = newRotation;

	// Update the TunnelTravelers attached to this Tunnel
	LinkedListIterator<TunnelTraveler>* iter = travelers->Iterator();
	while (iter->HasNext()) {
		Vector2 center = GetEntity()->GetAttachment<Transform>()->position;

		TunnelTraveler* traveler = iter->Next();
		traveler->TunnelUpdate(deltaTime, this);

		if (traveler->radius < innerRadius || traveler->radius > outerRadius)
			Level::DestroyEntity(traveler->GetEntity());
	}

	delete iter;
}
