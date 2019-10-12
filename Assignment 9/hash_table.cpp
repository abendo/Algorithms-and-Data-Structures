/**
 * ALBRIT BENDO
 * ADS HW 9
 * HASH TABLE
 **/

#include <iostream>

using namespace std;

// To create slots of the Hash-Table 
class Node {
    public:
        int key; // To find index
        int value; // The data
        Node(int key, int value); // Constructing the slot 
};

class HashTable {
    private:
        Node **arr;
        int maxSize;
        int currentSize;
    public:
        HashTable(); // Constructor
        int hashCode(int key); // The hash-function
        void insertNode(int key, int value); // Inserting nodes function
        int get(int key); // Searching for the key
        bool isEmpty(); // Checking if empty
};

// Implementing the parametric constructor
Node::Node(int new_key, int new_value) {
    this->key = new_key;
    this->value = new_value;
}

// Implementing the default constructor
HashTable::HashTable() {
    maxSize = 10; // Fixed size of 10 in my case
    currentSize = 0; // Counter 
    arr = new Node * [maxSize]; // Creating 10 entries in the table

    for(int i = 0; i < 10; i++) {
        arr[i] = NULL; // In default case all entries are assigned to NULL
    }
}

/*****************************************************************
 * I am using the general function "k mod m" as k and m will be  *
 * between 0 and m-1 (size), is easier to map integers to the    *
 * provided slots.                                               *
 *****************************************************************/ 
int HashTable::hashCode(int new_key) {
    return new_key % maxSize;
}

// Inserting the slot
void HashTable::insertNode(int new_key, int new_value) {
    int index = hashCode(new_key); // Index provided by the hashCode()
    Node *new_node = new Node(new_key, new_value); // Creating the slot

// While there are free slots and NO collisions
    while(arr[index] != NULL && arr[index]->key != new_key) {
        index++;
        index %= this->maxSize;
    }

    if(arr[index] == NULL) {
        currentSize++; // Keeping track of the current size
    }

    arr[index] = new_node; // Making the assertion
}

// Find the value of the key
int HashTable::get(int key) {
    int index = hashCode(key);

    while(arr[index] != NULL) {
        int count=0;
        if(count++ > this->maxSize) { // To avoid forever loops
            break;
        }

        if(arr[index]->key == key) {
            return arr[index]->value;
        }
        index++;
        index %= this->maxSize;
    }  

    return 0; // If no success
}

bool HashTable::isEmpty() {
    return this->currentSize == 0; // Return True if empty
                // else False
}

int main()
{
    HashTable *hash = new HashTable;
    hash->insertNode(1, 1);
    hash->insertNode(2, 15);
    hash->insertNode(3, 3);

    if(hash->isEmpty() == false) {
        cout << "Not Empty" << endl;
    } else {
        cout << "Empty" << endl;
    }
    
    cout << hash->get(2) << endl;

    return 0;
}

/// Reference: https://www.geeksforgeeks.org/implementing-hash-table-open-addressing-linear-probing-cpp/