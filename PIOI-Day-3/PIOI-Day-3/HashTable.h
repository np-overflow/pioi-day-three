#pragma once
#include<string>
#include<iostream>
using namespace std;

const int MAX_SIZE = 101;
typedef string ItemType;
typedef string KeyType;

struct Node
{
	KeyType  key;   // search key
	ItemType item;	// data item
	Node* next;	// pointer pointing to next item
};

class HashTable
{
private:
	Node* items[MAX_SIZE];
	int  size;			// number of items in the Hash Table

public:
	// constructor
	HashTable();

	// destructor
	~HashTable();

	int hash(KeyType key);

	// add a new item with the specified key to the Hash Table
	bool add(KeyType newKey, ItemType newItem);

	// remove an item with the specified key in the Hash Table
	void remove(KeyType key);

	// get an item with the specified key in the Hash Table (retrieve)
	ItemType get(KeyType key);

	// check if the Hash Table is empty
	bool isEmpty();

	// check the size of the Hash Table
	int getLength();

	// display the items in the Hash Table
	void print();
};