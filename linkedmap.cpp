#include "linkedmap.h"

using namespace std;

/**
 * Create a node that hold copies of this key/value pair
 * @param key A key which is hashable (and by extension cloneable)
 * @param value The value, which is cloneable
 */
LinkedNode::LinkedNode(Hashable* key, Cloneable* value) {
    this->key = (Hashable*)key->clone();
    this->value = value->clone();
    next = NULL;
}

/**
 * Delete this node, also deleting copies of the key/value
 * that were made
 */
LinkedNode::~LinkedNode() {
    delete key;
    delete value;
}

/**
 * A private helper method that removes the node
 * at the front of the map
 */
void LinkedMap::removeFirst() {
    numOps++;
    LinkedNode* oldHead = head;
    head = head->next;
    delete oldHead;
}

/**
 * Constructor: Start off with an empty map where the head
 * is a null pointer
 */
LinkedMap::LinkedMap() {
    head = NULL;
}

/**
 * Clear this linked list while properly de-allocating memory
 * by removing each node one at a time
 */
LinkedMap::~LinkedMap() {
    // Delete all nodes that have been allocated
    while (head != NULL) {
        removeFirst();
    }
}

/**
 * A simplified version of the put command where we add
 * a key/value pair to the map, without worrying about
 * duplicate keys
 * @param key A key which is hashable (and by extension cloneable)
 * @param value The value, which is cloneable
 */
void LinkedMap::put(Hashable* key, Cloneable* value) {
    // Add a new key/value pair at the beginning
    LinkedNode* newLinkedNode = new LinkedNode(key, value);
    if (head == NULL) {
        head = newLinkedNode;
    }
    else {
        newLinkedNode->next = head;
        head = newLinkedNode;
    }
    numOps++;
}

/** 
* Find the value corresponding to a key
* @param key A key which is hashable (and by extension cloneable)
* @return The corresponding value, or nullpointer if key is not in the map
*/
Cloneable* LinkedMap::get(Hashable* key) {
    Cloneable* ret = NULL;
    LinkedNode* node = head;
    while (node != NULL && !node->key->equals(key)) {
        numOps++;
        node = node->next;
    }
    if (node != NULL) {
        ret = node->value;
    }
    return ret;
}

/**
 * Remove a key/value pair and return
 * the corresponding value
 * @param key A key which is hashable (and by extension cloneable)
 * @return value A pointer to the associated copy of the value
 */
void LinkedMap::remove(Hashable* key) {
    if (head != NULL) {
        if (head->key->equals(key)) {
            removeFirst();
        }
        else {
            LinkedNode* last = head;
            LinkedNode* node = head->next;
            while (node != NULL && !node->key->equals(key)) {
                last = node;
                node = node->next;
                numOps++;
            } 
            if (node != NULL) {
                last->next = node->next;
                numOps++;
                delete node;
            }
        }
    }
}

/**
* Return true if the map contains this key
* or false otherwise
* @param key A key which is hashable (and by extension cloneable)
* @return true if key is in map, false otherwise
*/
bool LinkedMap::containsKey(Hashable* key) {
    bool contains = false;
    LinkedNode* node = head;
    while (node != NULL && !node->key->equals(key)) {
        node = node->next;
        numOps++;
    }
    if (node != NULL) {
        contains = true;
    }
    return contains;
}

/**
 * Dynamically create an array to hold all of the keys in
 * this map in an arbitrary order.
 * @param N A pointer to the location that will hold the size
 *          of the array
 * @return A pointer to the pointers of the keys in the list
 */
Hashable** LinkedMap::getKeyList(size_t* N) {
    LinkedNode* node = head;
    *N = 0;
    while (node != NULL) {
        (*N)++;
        node = node->next;
    }
    node = head;
    Hashable** keyList = new Hashable*[*N];
    size_t i = 0;
    while (node != NULL) {
        keyList[i] = node->key;
        i++;
        node = node->next;
    }
    return keyList;
}