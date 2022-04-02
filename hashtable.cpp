/***************************************************************************
Name: Natalia Ksenz
Coding 06
Purpose: The assignment to create a Hash Table class/object with standard
structure.

File: hashtable.cpp
***************************************************************************/

#include "hashtable.h"

Hashtable::Hashtable() {
    count = 0;
    for (int i = 0; i < HASHTABLESIZE; i++) {
        hashtable[i] = new LinkedList;
    }
}

int Hashtable::hash(int id) {
    // guarantees a position between 0 and HASHTABLESIZE - 1
    return id % HASHTABLESIZE;
}

bool Hashtable::insertEntry(int id, string *data) {
    bool inserted = false;
    int position = hash(id);

    if (hashtable[position]->addNode(id, data)) {
        inserted = true;
        count++;
    }

    return inserted;
}

bool Hashtable::removeEntry(int id) {
    bool del = false;
    int position = hash(id);

    return del;
}

string Hashtable::getData(int id) {
    string ret = "";
    int position = hash(id);


    return ret;
}

void Hashtable::printTable() {
    for (int i = 0; i < HASHTABLESIZE; i++) {
        hashtable[i]->printList(i);
    }
}

int Hashtable::getCount() {
    return count;
}
