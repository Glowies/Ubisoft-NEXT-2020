#include "stdafx.h"
#include "Level.h"

Level::Level()
{
	entities = new LinkedList<Entity>();
	markedForDestruction = new LinkedList<Entity>();
	currentLevel = this;
}

Level::~Level()
{
	LinkedListIterator<Entity>* iter = entities->Iterator();
	while (iter->HasNext()) {
		Entity* ent = iter->Next();
		delete ent;
	}
	delete iter;

	delete entities;
}

void Level::Init()
{
	LinkedListIterator<Entity>* iter = entities->Iterator();
	while (iter->HasNext()) {
		Entity* ent = iter->Next();
		ent->Init();
	}
	delete iter;
}

void Level::Update(float deltaTime)
{
	// Update entities
	LinkedListIterator<Entity>* iter = entities->Iterator();
	while (iter->HasNext()) {
		Entity* ent = iter->Next();
		if (ent->IsActive())
			ent->Update(deltaTime);
	}
	delete iter;

	// Check for collisions
	iter = entities->Iterator();
	while (iter->HasNext()) {
		Entity* ent = iter->Next();
		Collider* coll = ent->GetAttachment<Collider>();

		if (ent->IsActive() && coll != NULL) {
			LinkedListIterator<Entity>* innerIter = entities->Iterator();
			while (innerIter->HasNext()) {
				Entity* otherEnt = innerIter->Next();
				Collider* otherColl = otherEnt->GetAttachment<Collider>();

				// Trigger OnCollision calls if the Entity collides with another Entity
				if (ent != otherEnt && otherEnt->IsActive() && otherColl != NULL && coll->CollidesWith(otherColl)) {
					ent->OnCollision(otherColl);
				}
			}
			delete innerIter;
		}
	}
	delete iter;

	// Destroy marked Entities
	iter = markedForDestruction->Iterator();
	while (iter->HasNext()) {
		Entity* ent = iter->Next();

		// Remove Entity from any Tunnel it might appear in
		LinkedListIterator<Entity>* innerIter = entities->Iterator();
		while (innerIter->HasNext()) {
			Entity* innerEnt = innerIter->Next();
			if (innerEnt == ent)
				continue;

			Tunnel* tunnel = innerEnt->GetAttachment<Tunnel>();
			if (tunnel != NULL) {
				tunnel->RemoveTraveler(ent->GetAttachment<TunnelTraveler>());
			}
		}
		delete innerIter;

		RemoveEntity(ent);
		delete ent;
		markedForDestruction->Remove(ent);
	}
	delete iter;
}

void Level::Render()
{
	LinkedListIterator<Entity>* iter = entities->Iterator();
	while (iter->HasNext()) {
		Entity* ent = iter->Next();
		if (ent->IsActive())
			ent->Render();
	}
	delete iter;
}

void Level::AddEntity(Entity* ent)
{
	if(!entities->Contains(ent))
		entities->Add(ent);
}

void Level::RemoveEntity(Entity* ent)
{
	entities->Remove(ent);
}

void Level::MarkForDestruction(Entity* ent)
{
	if(!markedForDestruction->Contains(ent))
		markedForDestruction->Add(ent);
}

void Level::SpawnEntity(Entity* ent)
{
	currentLevel->AddEntity(ent);
	ent->Init();
}

void Level::DestroyEntity(Entity* ent)
{
	currentLevel->MarkForDestruction(ent);
}

Level* Level::currentLevel = NULL;