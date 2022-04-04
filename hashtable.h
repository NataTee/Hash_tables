/***************************************************************************
Name: Natalia Ksenz
Coding 06
Purpose: The assignment to create a Hash Table class/object with standard
structure.

File: hashtable.h
***************************************************************************/

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include <iostream>
#include <string>       /* string */
#include "linkedlist.h"

#define HASHTABLESIZE 15

using std::cout;
using std::endl;

class Hashtable {

public:
    Hashtable();
    ~Hashtable();

    bool insertEntry(int, string*);
    string getData(int);
    bool removeEntry(int);
    int getCount();
    void printTable();

    private:

    int hash(int);

    LinkedList *hashtable[HASHTABLESIZE];
    int count;
};

#endif /* HASHTABLE_HASHTABLE_H */
