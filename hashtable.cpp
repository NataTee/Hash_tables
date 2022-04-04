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

Hashtable::~Hashtable() {
    for (int i = 0; i < HASHTABLESIZE; i++) {
        if (hashtable[i]) {
            delete hashtable[i];
        }
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
    for (int i = 0; i < HASHTABLESIZE; i++) {
        if (hashtable[i]->deleteNode(id)) {
            del = true;
            count--;
        }
    }
    return del;
}

string Hashtable::getData(int id) {
    string ret = "";
    //making temporary data holder for testing
    Data tmpData;
    for (int i = 0; i < HASHTABLESIZE; i++) {
        if (hashtable[i]->getNode(id, &tmpData)) {
            ret = tmpData.data;
        }
    }
    return ret;
}

void Hashtable::printTable() {
    for (int i = 0; i < HASHTABLESIZE; i++) {
        cout << "Entry " << i << ": " ;
        hashtable[i]->printList();
        cout << endl;
    }
}

int Hashtable::getCount() {
    return count;
}
