#pragma once

template <class T>
struct node {
	node<T>(T* dat) {
		data = dat;
		next = NULL;
	}

	T* data;
	node<T> *next;

};

/**
 Generic class used to iterate over LinkedLists.
 A generic class that can be used to iterate over a LinkedList specialized to type T.
*/
template <class T>
class LinkedListIterator
{
public:
	/**
	Constructor for LinkedListIterator.
	Constructs a LinkedListIterator starting at the node <start>.

	@param start The node at which iteration will start.
	*/
	LinkedListIterator(node<T>* start);

	/**
	Reset the iterator to the start.
	Reset the iterator to point to the starting node.
	*/
	void Reset();

	/**
	Get next item the the iterator.
	Return the next element that the iterator is pointing to.

	@return A pointer to next element if there is a next element to be found, NULL otherwise.
	*/
	T* Next();

	/**
	Check for next element.
	Check and return whether or not there is any more elements left to iterate over.

	@return true if there is an element left to iterate over, false otherwise.
	*/
	bool HasNext();
private:
	node<T>* head;
	node<T>* curr;
};

/**
 Generic LinkedList class.
 A generic LinkedList class that can store elements of type T.
*/
template <class T>
class LinkedList
{
public:
	/**
	 Constructor for LinkedList.
	 Constructs an empty LinkedList.
	*/
	LinkedList();

	/**
	 Destructor for LinkedList.
	 Destructs the LinkedList by deallocating all nodes.
	*/
	~LinkedList();

	/**
	 Check if LinkedList is empty.
	 @return true if LinkedList is empty, false otherwise.
	*/
	bool IsEmpty();

	/**
	 Indexing method for LinkedList.
	 Index into LinkedList and return the indexed element.

	 @param index The index of the element to return.
	 @return Pointer to the element at given index.
	*/
	T* Get(int index);

	/**
	 Push method for LinkedList.
	 Places a new element at the end of the LinkedList.

	 @param element The element to be added to the LinkedList.
	*/
	void Add(T* element);

	/**
	 Remove method for LinkedList.
	 Removes the given element from the LinkedList.

	 @param element The element to be removed from the LinkedList.
	*/
	void Remove(T* element);

	/**
	 Size of LinkedList.

	 @return Current size of the LinkedList.
	*/
	int Size();

	/**
	 Check if LinkedList contains an element.

	 @param element The element to be checked for.
	*/
	bool Contains(T* element);

	/**
	 Iterator for the LinkedList

	 @return A new iterator that points to the head of the LinkedList.
	*/
	LinkedListIterator<T>* Iterator();

private:
	node<T>* head;
	node<T>* tail;
	int size;
};
