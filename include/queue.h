#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <optional>
#include "node.h"

typedef struct {
	node* head;
	node* tail;
}queue_ll;

queue_ll* createLLQueue();

void enqueue(queue_ll* q, int value);

int dequeue(queue_ll* q);

bool isEmpty(queue_ll* q);

int peek(queue_ll* q);

void display(queue_ll* q);

void deleteQueue(queue_ll** q);

// =================== Queue Array part ==================
class QueueArr {
private:
	const int size;			// The size of the array, ethier user-passed parameter or default is 10
	int* arr;				// intialized here as a pointer as the size will be determined in the constructor
	int _front, rear;
public:
	// constructors
	QueueArr();
	QueueArr(int size);
	~QueueArr();

	// check helpers
	bool isEmpty();
	bool isFull();

	// main queue functions
	void enqueue(int value);
	int dequeue();				// Dequeue: front() + pop()
	void clear();
	int length();			// Returns the current length of the queue
	int capacity();			// Returns the total size of the queue
	int available();		// Returns the number of available spaces in the queue

	// Displays the whole queue
	void print();

	//retrieve without changing the queue
	int front();

};