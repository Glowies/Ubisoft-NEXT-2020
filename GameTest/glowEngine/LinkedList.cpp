#include "stdafx.h"
#include "LinkedList.h"
#include "GlowEngine.h"

// LinkedList Methods

template <class T>
LinkedList<T>::LinkedList() {
	head = NULL;
	tail = NULL;
	size = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
	node<T>* prev = NULL;
	node<T>* curr = head;

	while (curr != NULL) {
		if (prev != NULL) {
			delete prev;
		}

		prev = curr;
		curr = curr->next;
	}

	if (prev != NULL) {
		delete prev;
	}
}

template <class T>
bool LinkedList<T>::IsEmpty() {
	return head == NULL;
}

template <class T>
T* LinkedList<T>::Get(int index) {
	node<T>* curr = head;
	int count = 0;

	do {
		if (count == index)
			return curr->data;

		curr = curr->next;
		count++;
	} while (curr != NULL);
	
	// Index is out of range
	return NULL;
}

template <class T>
void LinkedList<T>::Add(T* element) {
	size++;

	if (tail == NULL) {
		head = new node<T>(element);
		tail = head;
		head->next = NULL;
		return;
	}

	tail->next = new node<T>(element);
	tail->next->next = NULL;
	tail = tail->next;
}

template<class T>
void LinkedList<T>::Remove(T* element)
{
	node<T>* prev = NULL;
	node<T>* curr = head;

	while (curr != NULL) {
		if (curr->data == element) {
			if (prev == NULL) { // Element is the head
				head = NULL;
				tail = NULL;
			}
			else {
				if (curr == tail)
					tail = prev;
				prev->next = curr->next;
			}

			delete curr;
			size--;
			return;
		}

		prev = curr;
		curr = curr->next;
	}
}

template <class T>
int LinkedList<T>::Size() {
	return size;
}

template<class T>
bool LinkedList<T>::Contains(T* element)
{
	LinkedListIterator<T>* iter = Iterator();
	while (iter->HasNext()) {
		T* e = iter->Next();
		if (e == element) {
			delete iter;
			return true;
		}
	}
	delete iter;
	return false;
}

template <class T>
LinkedListIterator<T>* LinkedList<T>::Iterator() {
	return new LinkedListIterator<T>(head);
}


// LinkedListIterator Methods
template <class T>
LinkedListIterator<T>::LinkedListIterator(node<T>* start) {
	head = start;
	curr = NULL;
	Reset();
}

template <class T>
void LinkedListIterator<T>::Reset() {
	curr = head;
}

template <class T>
T* LinkedListIterator<T>::Next() {
	if (curr == NULL)
		return NULL;
	T* result = curr->data;
	curr = curr->next;
	return result;
}

template <class T>
bool LinkedListIterator<T>::HasNext() {
	return curr != NULL;
}


template class LinkedList<Level>;
template class LinkedList<Entity>;
template class LinkedList<TunnelTraveler>;
template class LinkedList<TextRenderer>;
template class LinkedList<Renderer>;
template class LinkedList<Attachment>;
template class LinkedListIterator<Level>;
template class LinkedListIterator<Entity>;
template class LinkedListIterator<TunnelTraveler>;
template class LinkedListIterator<TextRenderer>;
template class LinkedListIterator<Renderer>;
template class LinkedListIterator<Attachment>;