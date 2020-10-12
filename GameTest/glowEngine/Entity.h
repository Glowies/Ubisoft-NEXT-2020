#pragma once
#include "LinkedList.h"
#include "attachments/Attachments.h"


class Attachment;

/**
Baseclass for anything that can be placed in a Level.
Every Entity is a collection of Attachments, 
all of which define its position, its behaviour and how its going to be rendered.
*/
class Entity
{
public:
	/**
	 Constructor for Entity.
	 Constructs an new Entity.
	*/
	Entity();

	/**
	 Destructor for Entity.
	 Destructs the Entity by deleting its Attachments.
	*/
	~Entity();

	/**
	 Check if Entity is active.

	 @return true of Entity is active, false otherwise
	*/
	bool IsActive();

	/**
	 Activate or deactivate Entity.

	 @param val Activate if true, deactivate otherwise.
	*/
	void SetActive(bool val);

	/**
	Create and add new Attachment of type T to the Entity.
	@return The newly created Attachment.
	*/
	template <class T>
	T* AddAttachment();

	/**
	Method to access Attachments on this Entity.
	@return The first Attachment of type T that is found in the attachment list of the Entity.
	*/
	template <class T>
	T* GetAttachment();

	/**
	Method to retreive a list of Attachments on this Entity.
	@return A LinkedList of the attachments found.
	*/
	template <class T>
	LinkedList<T>* GetAttachments();

	/**
	Initialize this Entity.
	Initializes this Entity and the Attachments attached to it.
	*/
	void Init();

	/**
	Update this Entity.
	Updates every Attachment on this Entity.

	@param deltaTime Time elapsed between the last frame and the current frame.
	*/
	void Update(float deltaTime);

	/**
	Render this Entity.
	Render this Entity according to its Renderer attachment, if it has one.
	*/
	void Render();

	/**
	 Trigger Collision calls on all Attachments.

	 @param other The Collider that the Entity collided with.
	*/
	void OnCollision(Collider* other);

private:
	bool activated;
	LinkedList<Attachment>* attachmentList;
};

template<class T>
inline
T* Entity::AddAttachment()
{
	T* result = new T(this);
	attachmentList->Add(result);
	return result;
}

template<class T>
inline
T* Entity::GetAttachment()
{
	LinkedListIterator<Attachment>* iter = attachmentList->Iterator();
	while (iter->HasNext()) {
		Attachment* attachment = iter->Next();

		T* result = dynamic_cast<T*>(attachment);
		if (result != NULL) {
			delete iter;
			return result;
		}
	}
	delete iter;

	return NULL;
}

template<class T>
inline
LinkedList<T>* Entity::GetAttachments()
{
	LinkedList<T>* result = new LinkedList<T>();

	LinkedListIterator<Attachment>* iter = attachmentList->Iterator();
	while (iter->HasNext()) {
		Attachment* attachment = iter->Next();

		T* casted = dynamic_cast<T*>(attachment);
		if (casted != NULL) {
			result->Add(casted);
		}
	}
	delete iter;

	return result;
}