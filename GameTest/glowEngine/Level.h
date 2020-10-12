#pragma once
#include "LinkedList.h"
#include "Entity.h"

/**
 Class representing a level in the game.
 Each Level is simply a list of Entities that are present in that level.
*/
class Level
{
public:
    /**
     Constructor for Level.
     Constructs an new Level.
    */
    Level();

    /**
     Destructor for Level.
     Destructs the Level by deleting the Entities in it.
    */
    ~Level();

    /**
     Initialize all Entities in this Level.
    */
    void Init();

    /**
     Update all Entities in this Level.

     @param deltaTime Time elapsed between the last frame and the current frame.
    */
    void Update(float deltaTime);

    /**
     Render all Entities in this Level.
    */
    void Render();

    /**
     Add an Entity to this Level.

     @param ent Pointer to an Entity object.
    */
    void AddEntity(Entity* ent);

    /**
     Remove an Entity from this Level.

     @param ent Pointer to an Entity object.
    */
    void RemoveEntity(Entity* ent);

    /**
     Mark an Entity for destruction.
     Marked Entities will be destroyed after the next Update call.
    */
    void MarkForDestruction(Entity* ent);

    /**
     Spawn an Entity on the current Level.

     @param ent The Entity to spawn.
    */
    static void SpawnEntity(Entity* ent);

    /**
     Destroy an Entity on the current Level.

     @param ent The Entity to destroy.
    */
    static void DestroyEntity(Entity* ent);
    
    /**
	 Look for an Attachment of type T in the current level.
	*/
    template <class T>
    static T* FindAttachment();

    /**
     The current Level that is being run.
     This is the last Level object to be instantiated.
    */
    static Level* currentLevel;

private:
    LinkedList<Entity>* entities;
    LinkedList<Entity>* markedForDestruction;
};

template<class T>
inline
static T* Level::FindAttachment()
{
    LinkedListIterator<Entity>* iter = currentLevel->entities->Iterator();
    while (iter->HasNext()) {
        Entity* ent = iter->Next();
        T* result = ent->GetAttachment<T>();
        if (result) {
            delete iter;
            return result;
        }
    }
    delete iter;
    return NULL;
}