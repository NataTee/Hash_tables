/***************************************************************************
Name: Natalia Ksenz
Coding 06
Purpose: The assignment to create a Hash Table class/object with standard
structure.

File: linkedlist.h
***************************************************************************/


 #ifndef LINKEDLIST_H
 #define LINKEDLIST_H

 #include <iostream>     /* cout, endl */
 #include "string"
 #include "data.h"

 using std::cout;
 using std::endl;
 using std::string;

 class LinkedList {

 public:

     LinkedList();
     ~LinkedList();

     bool addNode(int, string*);
     bool deleteNode(int);
     bool getNode(int, Data*);
     bool printList();
     int getCount();
     bool clearList();
     bool exists(int);

 private:

     Node *head;   // a pointer to the first node or NULL if the list is empty.

     void fillIt(int, string*, Node*&);
     void addHead(Node*&, Node*&, bool&);
     void addMiddle(Node*&, Node*&, bool&);
     void addTail(Node*&, Node*&, bool&);
     void deleteHead(Node*&, bool&);
     void deleteMiddle(Node*&, bool&);
     void deleteTail(Node*&, bool&);
 };
 #endif /* LINKEDLIST_H */
