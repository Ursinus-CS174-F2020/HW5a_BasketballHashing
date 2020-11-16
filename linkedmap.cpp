#include "linkedmap.h"

using namespace std;

Node::Node(Hashable* key, void* value) {
    this->key = key;
    this->value = value;
    next = nullptr;
}

void LinkedMap::removeFirst() {
    Node* oldHead = head;
    head = head->next;
    delete oldHead;
}

LinkedMap::LinkedMap() {
    head = nullptr;
}

LinkedMap::~LinkedMap() {
    // Delete all nodes that have been allocated
    while (head != nullptr) {
        removeFirst();
    }
}

void LinkedMap::put(Hashable* key, void* value) {
    // Add a new key/value pair at the beginning
    Node* newNode = new Node(key, value);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

/* 
* Find the value corresponding to a key
*/
void* LinkedMap::get(Hashable* key) {
    void* ret = nullptr;
    Node* node = head;
    while (node != nullptr && !node->key->equals(key)) {
        node = node->next;
    }
    if (node != nullptr) {
        ret = node->next;
    }
    return ret;
}

/**
 * Remove a key/value pair and return
 * the corresponding value
 */
void* LinkedMap::remove(Hashable* key) {
    void* ret = nullptr;
    if (head != nullptr) {
        if (head->key->equals(key)) {
            ret = head->value;
            removeFirst();
        }
        else {
            Node* last = head;
            Node* node = head->next;
            while (node != nullptr && !node->key->equals(key)) {
                last = node;
                node = node->next;
            } 
            if (node != nullptr) {
                ret = node->value;
                last->next = node->next;
            }
        }
    }
    return ret;
}

/**
* Return true if the map contains this key
* or false otherwise
*/
bool LinkedMap::containsKey(Hashable* key) {
    bool contains = false;
    Node* node = head;
    while (node != nullptr && !node->key->equals(key)) {
        node = node->next;
    }
    if (node != nullptr) {
        contains = true;
    }
    return contains;
}

/**
 * 
 */
Hashable** LinkedMap::getKeyList(size_t* N) {
    Node* node = head;
    *N = 0;
    while (node != nullptr) {
        (*N)++;
        node = node->next;
    }
    node = head;
    Hashable** keyList = new Hashable*[*N];
    size_t i = 0;
    while (node != nullptr) {
        keyList[i] = node->key;
        i++;
        node = node->next;
    }
    return keyList;
}

void** LinkedMap::getValueList(size_t* N) {
    Node* node = head;
    *N = 0;
    while (node != nullptr) {
        (*N)++;
        node = node->next;
    }
    node = head;
    void** valueList = new void*[*N];
    size_t i = 0;
    while (node != nullptr) {
        valueList[i] = node->value;
        i++;
        node = node->next;
    }
    return valueList;
}