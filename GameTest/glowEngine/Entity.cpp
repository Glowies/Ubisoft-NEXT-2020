#include "stdafx.h"
#include "Entity.h"


Entity::Entity()
{
	attachmentList = new LinkedList<Attachment>();
	activated = true;

	AddAttachment<Transform>();
}

Entity::~Entity()
{
	LinkedListIterator<Attachment>* iter = attachmentList->Iterator();
	while (iter->HasNext()) {
		Attachment* attachment = iter->Next();
		delete attachment;
	}
	
	delete iter;
	delete attachmentList;
}

bool Entity::IsActive()
{
	return activated;
}

void Entity::SetActive(bool val)
{
	activated = val;
}

void Entity::Init()
{
	LinkedListIterator<Attachment>* iter = attachmentList->Iterator();
	while (iter->HasNext()) {
		Attachment* attachment = iter->Next();
		attachment->Init();
	}
	delete iter;
}

void Entity::Update(float deltaTime)
{
	LinkedListIterator<Attachment>* iter = attachmentList->Iterator();
	while (iter->HasNext()) {
		Attachment* attachment = iter->Next();
		if(attachment->IsActive())
			attachment->Update(deltaTime);
	}
	delete iter;
}

void Entity::Render()
{
	LinkedList<Renderer>* renderers = GetAttachments<Renderer>();
	LinkedListIterator<Renderer>* iter = renderers->Iterator();
	while (iter->HasNext()) {
		Renderer* renderer = iter->Next();
		if (renderer->IsActive()) {
			renderer->Draw();
		}
	}
	delete iter;
	delete renderers;
}

void Entity::OnCollision(Collider* other)
{
	LinkedListIterator<Attachment>* iter = attachmentList->Iterator();
	while (iter->HasNext()) {
		Attachment* attachment = iter->Next();
		if (attachment->IsActive())
			attachment->OnCollision(other);
	}
	delete iter;
}
