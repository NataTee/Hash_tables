/***************************************************************************
Name: Natalia Ksenz
Coding 06
Purpose: The assignment to create a Hash Table class/object with standard
structure.

File: main.cpp
***************************************************************************/

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];

    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";

    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */

    // create your hash table object here
    cout << "Creating a hashtable...";
    Hashtable hashtable;
    cout << "done" << endl << endl;

    // show it is empty by calling getCount and printTable
    cout << "Checking the hashtable...\n";
    cout << "There are " << hashtable.getCount() << " entries in the table." << endl << endl;
    hashtable.printTable();
    cout << endl;

    // try and put ALL the test data into the table and show what happens
    cout << "Inserting Test Data..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        if (hashtable.insertEntry(ids[i], &strs[i])) {
            cout << "Adding id: " << ids[i] << ", data: " << strs[i] << endl;
            cout << "Entry inserted successfully." << endl;
        } else {
            cout << "Adding id: " << ids[i] << ", data: " << strs[i] << endl;
            cout << "Entry is not added." << endl;
        }
    }
    cout << endl;

    cout << "There are " << hashtable.getCount() << " entries in the table." << endl;
    hashtable.printTable();

    //randomly getting a few nodes
    cout << "\nTrying to insert few more nodes..." << endl;
    for (int i = 0; i < testdatasize; i+=3) {
        if (hashtable.insertEntry(ids[i], &strs[i])) {
            cout << "Adding id: " << ids[i] << ", data: " << strs[i] << endl;
            cout << "Entry inserted successfully." << endl;
        } else {
            cout << "Adding id: " << ids[i] << ", data: " << strs[i] << endl;
            cout << "Entry is not added." << endl;
        }
    }
    cout << endl;

    cout << "There are " << hashtable.getCount() << " entries in the table." << endl;
    hashtable.printTable();
    cout << endl;

    //randomly checking 5 nodes
    cout << "Checking data associated with id..." << endl;
    for (int i = 0; i < 5; i++) {
        int getid = rand() % MAXID + 1;
        cout << "Id: " << getid;
        cout << " , data: " << hashtable.getData(getid) << endl;
    }
    cout << endl;

    //deleting from the table random ids
    cout << "Trying to delete random id..." << endl;
    for (int i = 0; i < (testdatasize/3); i++) {
        int delid = rand() % MAXID + 1;
        cout << "Deleting " << delid << "... ";
        if (hashtable.removeEntry(delid)) {
            cout << "success" << endl;
        } else {
            cout << "failed" << endl;
        }
    }
    cout << endl;

    cout << "Checking the hashtable...\n";
    cout << "There are " << hashtable.getCount() << " entries in the table." << endl << endl;
    hashtable.printTable();
    cout << endl;

    //removing every second node from the table
    for (int i = 0; i < testdatasize; i+=2) {
        cout << "Deleting " << ids[i] << "... ";
        if (hashtable.removeEntry(ids[i])) {
            cout << "success" << endl;
        } else {
            cout << "failed" << endl;
        }
    }
    cout << endl;
    cout << "There are " << hashtable.getCount() << " entries in the table." << endl << endl;

    cout << "Inserting new data..." << endl;
    for (int i = 0; i < testdatasize; i+=3) {
        if (hashtable.insertEntry(ids[i], &strs[i])) {
            cout << "Adding id: " << ids[i] << ", data: " << strs[i] << endl;
            cout << "Entry inserted successfully." << endl;
        } else {
            cout << "Adding id: " << ids[i] << ", data: " << strs[i] << endl;
            cout << "Entry is not added." << endl;
        }
    }
    cout << endl;

    cout << "Checking the hashtable...\n";
    cout << "There are " << hashtable.getCount() << " entries in the table." << endl << endl;
    hashtable.printTable();
    cout << endl;

    //removing all the data from the table
    cout << "Removing all entries from the table..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << "Deleting " << ids[i] << "... ";
        if (hashtable.removeEntry(ids[i])) {
            cout << "success" << endl;
        } else {
            cout << "failed" << endl;
        }
    }
    cout << endl;

    cout << "Checking the hashtable...\n";
    cout << "There are " << hashtable.getCount() << " entries in the table." << endl << endl;
    hashtable.printTable();
    cout << endl;

    return 0;
}
