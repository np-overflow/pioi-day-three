#include "HashTable.h"
#include <iomanip>

// constructor
HashTable::HashTable()
{
    // Initialize all items to NULL
    for (int i = 0; i < MAX_SIZE; i++) {
        items[i] = NULL;
    }
    size = 0;  // Set the size to 0
};

// destructor
HashTable::~HashTable()
{
    for (int i = 0; i < MAX_SIZE; i++) {
        // Initialize the current and next pointers to new nodes
        Node* current = new Node;
        Node* next = new Node;
        current = items[i];
        // Check if the current item is not NULL
        if (current != NULL) {
            // Traverse through the linked list until the end
            while (current->next != NULL) {
                next = current->next;  // Update the next pointer
                delete current;  // Delete the current node
                current = next;  // Move to the next node
            }
        }
        delete current, next, items[i];  // Delete the current, next and items[i]
        current, next, items[i] = NULL;  // Set them to NULL
    }
};

// Function to get the value of the character for hashing
int charvalue(char c)
{
    // Check if the character is an alphabet
    if (isalpha(c))
    {
        // If the character is uppercase, return the difference between ASCII value of the character and ASCII value of 'A'
        if (isupper(c))
            return (int)c - (int)'A';
        // If the character is lowercase, return the difference between ASCII value of the character and ASCII value of 'a' plus 26
        else
            return (int)c - (int)'a' + 26;
    }
    else
        return -1;  // If the character is not an alphabet, return -1
}

// Function to calculate the hash value of a given key
int HashTable::hash(KeyType key)
{
    int hash = charvalue(key[0]);  // Initialize the hash value to the ASCII value of the first character of the key
    for (int i = 1; i < key.length(); i++) {
        // Multiply the hash value by 52 and add the value of the current character
        hash = hash * 52 + charvalue(key[i]);
        hash = hash % MAX_SIZE;  // Get the remainder when the hash value is divided by the size of the hash table
    }
    return hash;  // Return the hash value
};

// add a new item with the specified key to the Hash Table
// returns true if the item is added successfully, false if the key is already in the Hash Table
bool HashTable::add(KeyType newKey, ItemType newItem) {
    // calculate the hash value for the new key
    int index = hash(newKey);
    // if there is no item in the current index, create a new node with the key and item and add it to the Hash Table
    if (items[index] == NULL) {
        Node* node = new Node;
        node->key = newKey;
        node->item = newItem;
        node->next = NULL;
        items[index] = node;
        size++;
        return true;
    }
    else {
        // if there is already an item in the current index, traverse the linked list until the end or a node with the same key is found
        Node* current = items[index];
        if (current->key == newKey) {
            cout << endl << "Error! " << newKey << "," << newItem << " is a duplicated entry!" << endl;
            return false;
        }
        while (current->next != NULL) {
            current = current->next;
            if (current->key == newKey) {
                return false;
            }
        }
        // add a new node with the key and item at the end of the linked list
        Node* node = new Node;
        node->key = newKey;
        node->item = newItem;
        node->next = NULL;
        current->next = node;
        size++;
        return true;
    }
};

// remove an item with the specified key in the Hash Table
void HashTable::remove(KeyType key)
{
    // calculate the hash value for the key
    int index = hash(key);
    // if the index is not empty
    if (items[index] != NULL) {
        Node* current = new Node;
        current = items[index];

        // if the item to remove is at the head of the list
        if (current->key == key) {
            if (current->next != NULL) {
                items[index] = current->next;
            }
            else {
                items[index] = NULL;
            }
        }
        // if the item to remove is in the middle or end of the list
        else {
            Node* temp = new Node;
            while (current != NULL) {
                temp = current;
                current = current->next;
                if (current->key == key) {
                    if (current->next != NULL) {
                        temp->next = current->next;
                    }
                    else {
                        temp->next = NULL;
                    }
                    break;
                }
            }
        }
        delete current;
        current = NULL;
        size--;
    }
};

// get an item with the specified key in the Hash Table (retrieve)
ItemType HashTable::get(KeyType key)
{
    // get the index of the item to retrieve
    int index = hash(key);
    // if the index is not empty
    if (items[index] != NULL) {
        // if the item to retrieve is at the head of the list
        if (items[index]->key == key) {
            return items[index]->item;
        }
        // if the item to retrieve is in the middle or end of the list
        else {
            Node* current = new Node;
            current = items[index]->next;;
            while (current != NULL) {
                if (current->key == key) {
                    return current->item;
                }
                current = current->next;
            }
        }
    }
};

// check if the Hash Table is empty
bool HashTable::isEmpty() {
    return size == 0;
};

// check the number of items in the Hash Table 
int HashTable::getLength() {
    return size;
};

// display all the contents of the Hash Table
void HashTable::print() {
    cout << "Contents of Hash Table:" << endl;
    cout << "-----------------------" << endl;

    for (int i = 0; i < MAX_SIZE; i++) {
        if (items[i] != NULL) {
            Node* current = items[i];
            cout << "Index " << i << ": ";
            while (current != NULL) {
                cout << "(" << current->key << ", " << current->item << ")";
                if (current->next != NULL) {
                    cout << " -> ";
                }
                current = current->next;
            }
            cout << endl;
        }
    }
    cout << "-----------------------" << endl;
};


// Extra: Other Common Hashing Functions
// You may use these hashing function in replacement of the default
// hash function above

// Hash function using Mod Method
int mod_hash(int key, int table_size) {
    // return the remainder of key divided by table size
    return key % table_size;
}

// Hash function using Multiplication Method
int multiply_hash(int key, int table_size) {
    double A = 0.6180339887;
    // choose a constant A between 0 and 1
    // get the fractional part of the multiplication
    double frac = (key * A) - floor(key * A);
    // return the floor of the product of table size and fractional part
    return floor(table_size * frac);
}

// Hash function using Mid Square Method
int mid_square_hash(int key, int table_size) {
    // square the key
    int square = key * key;
    // counter for number of digits in the square
    int digits = 0;
    int temp = square;
    while (temp != 0) {
        digits++;
        temp /= 10;
    }
    // find the middle digit(s)
    int mid_digit = (digits / 2) + (digits % 2) - 1;
    // calculate divisor for extracting middle digit(s)
    int div = pow(10, mid_digit);
    // extract middle digit(s) and mod by table size
    int mid_num = (square / div) % table_size;
    return mid_num;
}

// Hash function using Folding Method
int folding_hash(int key, int table_size) {
    int sum = 0;
    int temp = key;
    while (temp > 0) {
        // extract two digits at a time
        int digit = temp % 100;
        sum += digit;
        temp /= 100;
    }
    // mod by table size to get hash value
    return sum % table_size;
}