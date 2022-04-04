/***************************************************************************
Name: Natalia Ksenz
Coding 06
Purpose: The assignment to create a Hash Table class/object with standard
structure.

File: linkedlist.cpp
***************************************************************************/

#include "linkedlist.h"

LinkedList::LinkedList() {
    head = NULL;
}

LinkedList::~LinkedList() {
    clearList();
}

bool LinkedList::addNode(int id, string *info) {
    bool added;
    if(id > 0 && *info != ""){
        if (head != NULL) {
            Node *current = head;
            while ((current->next != NULL) && (current->data.id != id)) {
                current = current->next;
            }
            if (current->data.id == id) {
                added = false;
            }
            else {
                Node *newNode = new Node;
                fillIt(id, info, newNode);
                addTail(current, newNode, added);
                added = true;
            }
        }
        else {
            Node *newNode = new Node;
            fillIt(id, info, newNode);
            head = newNode;
            added = true;
        }
    }
    return added;
}

bool LinkedList::deleteNode(int id) {
    bool deleted;
    if (head != NULL) {
        Node *current = head;
        while ((current->data.id != id) && (current->next != NULL)) {
          current = current->next;
        }
        if (current->data.id == id) {
            if (current->prev == NULL) {
                deleteHead(current, deleted);
            }
            else if (current->next == NULL) {
                deleteTail(current, deleted);
            }
            else {
                deleteMiddle(current, deleted);
            }

        }
        else {
            deleted = false;
        }
    }
    else {
        deleted = false;
    }
    return deleted;
}

bool LinkedList::getNode(int id, Data *data) {
    bool found = false;
    Node *current = head;
    if (current != NULL) {
        while ((current->data.id != id) && (current->next != NULL)) {
            current = current->next;
        }
        if (current->data.id == id) {
            data->id = current->data.id;
            data->data = current->data.data;
            found = true;
        }
        else {
            data->id = -1;
            data->data = "";
        }
    }
    return found;
}

bool LinkedList::printList() {
    Node *current = head;
    if (current == NULL) {
        cout << "EMPTY";
    }
    else {
        cout << current->data.id;
        while(current->next){
            current = current->next;
            cout << " --> " << current->data.id;
        }
    }
    return true;
}

int LinkedList::getCount() {
    Node *current = head;
    int count = 0;
    if (current != NULL) {
        count++;
        while (current = current->next) {
            count++;
        }
    }
    return count;
}

bool LinkedList::clearList() {
    bool deleted = false;
    if (head != NULL) {
        Node *current = head;
        while (current != NULL) {
            head = head->next;
            delete current;
            current = current->next;
            deleted = true;
        }
        head = NULL;
        delete head;
    }
    return deleted;
}

bool LinkedList::exists(int id) {
    bool exist;
    Node *current = head;
    while ((current->data.id != id) && (current->next != NULL)) {
        current = current->next;
    }
    if (current->data.id == id) {
        exist = true;
    }
    else {
        exist = false;
    }
    return exist;
}

void LinkedList::addHead(Node* &head, Node* &newNode, bool &added) {
    head->prev = newNode;
    newNode->next = head;
    newNode->prev = NULL;
    head = newNode;
    added = true;
}

void LinkedList::addMiddle(Node* &current, Node* &newNode, bool &added) {
    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;
    added = true;
}

void LinkedList::addTail(Node* &current, Node* &newNode, bool &added) {
    newNode->next = NULL;
    newNode->prev = current;
    current->next = newNode;
    added = true;
}

void LinkedList::fillIt(int id, string *info, Node* &newNode) {
    newNode->data.id = id;
    newNode->data.data = *info;
    newNode->next = NULL;
    newNode->prev = NULL;
}

void LinkedList::deleteHead(Node* &current, bool &deleted){
    if (current->next != NULL) {
        head = current->next;
        current->next->prev = NULL;
        current->next = NULL;
    }
    else {
        head = NULL;
    }
    delete current;
    deleted = true;
}

void LinkedList::deleteMiddle(Node* &current, bool &deleted){
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    deleted = true;
}

void LinkedList::deleteTail(Node* &current, bool &deleted){
    current->prev->next = NULL;
    current->prev = NULL;
    delete current;
    deleted = true;
}
